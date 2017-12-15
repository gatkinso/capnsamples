#include <iostream>
#include <capnp/message.h>
#include <capnp/compat/json.h>

#include "myproto.cp.h"

void test1()
{
    ::capnp::MallocMessageBuilder message;
    
    MyMsg::Builder mmbuilder = message.initRoot<MyMsg>();

    ::capnp::List<::capnp::Text>::Builder mypets = mmbuilder.initPets(3);

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