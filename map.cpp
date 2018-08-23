#include <iostream>
#include <map>

void eraseItemInMap(){
    std::cout << " -- How to erase item while iterating a map -- " << std::endl; 

    std::map<int,int> myMap = { {0,0}, {1,1}, {2,2} };
    for( const auto& i:myMap ){
        std::cout << i.first << ":" << i.second << std::endl;
    }

    auto iter = myMap.begin();
    while( iter != myMap.end() ){

        // erase element with key == 1
        if( iter->first == 1 )
            iter = myMap.erase( iter );
        else
            iter++;
    }
    
    std::cout << "    After delete  " << std::endl; 

    for( const auto& i:myMap ){
        std::cout << i.first << ":" << i.second << std::endl;
    }
}


