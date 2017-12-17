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

#include "hello.capnp.h"

void do_sample()
{
    //Instantiate a builder
    capnp::MallocMessageBuilder message;
    
    Hello::Builder hellobuilder = message.initRoot<Hello>();
    
    // Set the field value
    hellobuilder.setMystring("Hello CapnProto!");

    //Instantiate a reader
    Hello::Reader helloreader = message.getRoot<Hello>();
    
    //Print out the field value
    std::cout << helloreader.getMystring().cStr() << std::endl;
}


int main(int argc, const char* argv[])
{
    do_sample();

    return 0;
}
