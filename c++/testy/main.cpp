/*
MIT License

Copyright(c) 2017

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <iostream>
#include <capnp/message.h>
#include <capnp/compat/json.h>

#include "myproto.capnp.h"

void test1()
{
    capnp::MallocMessageBuilder message;
    
    MyMsg::Builder mmbuilder = message.initRoot<MyMsg>();

    capnp::List<::capnp::Text>::Builder mypets = mmbuilder.initPets(3);

    mmbuilder.setId(123);

    mmbuilder.setName("Geoffrey");

    mypets.set(0, "Jessie");
    mypets.set(1, "Jethro");
    mypets.set(2, "Josey");

/////////////////

    MyMsg::Reader mmreader = message.getRoot<MyMsg>();

    std::cout << mmreader.getId() << std::endl;
    std::cout << mmreader.getName().cStr() << std::endl;

    for (int i = 0; i < mmreader.getPets().size(); i++)
    {
        std::cout << mmreader.getPets()[i].cStr() << std::endl;
    }

/////////////////

    capnp::JsonCodec jscodec;

    jscodec.setPrettyPrint(true);

    kj::String kjs = jscodec.encode(mmreader);

    std::cout << kjs.cStr() << std::endl;
}


int main(int argc, const char* argv[])
{
	std::cout << "Hello Capn Proto" << std::endl;

	test1();

	return 0;
}