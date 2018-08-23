#include <functional>
#include <map>
#include <string>
#include <iostream>

#include "notes.hpp"


using FunctionHandlerMap = std::map< std::string, std::function< void(const std::string&) >>;
FunctionHandlerMap myHandlerMap 
{
    { "key1",
        [](const std::string& s) { std::cout << s << std::endl; }
    },
    { "key2",
        [](const std::string& s) { std::cout << s << std::endl; }
    }
};


void functionHandlerMapNote(){

    std::cout << "----- How to store function handler in a map --- " << std::endl;

    const std::string key = "key1";

    if( myHandlerMap.find(key) == myHandlerMap.end() ){
        throw(std::runtime_error("unknown type"));
    }

    const std::string value = "print me";
    myHandlerMap.at(key)(value);
}

