#include "doctest.h"
using namespace doctest;

#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include "Board.hpp"
using namespace std;
using ariel::Direction;
using ariel::Board;

TEST_CASE("post_&&_read"){
    ariel::Board myBoard;

    myBoard.post(0,0,Direction::Horizontal,"looking for a new house?");
    CHECK(myBoard.read(0,0,Direction::Horizontal,26) == "looking for a new house?__");

    myBoard.post(5,18,Direction::Horizontal,"looking for a new house?");
    CHECK(myBoard.read(2,18,Direction::Horizontal,29) == "___looking for a new house?__");

    myBoard.post(3,0,Direction::Horizontal,"ameer a cs teacher 0502211343");
    CHECK(myBoard.read(19,0,Direction::Horizontal,10) == "er 0502211");
    
    myBoard.post(12,13,Direction::Horizontal,"party in ariel at 8:00");
    CHECK(myBoard.read(13,13,Direction::Horizontal,5) == "arty ");
    
    myBoard.post(1,0,Direction::Horizontal,"looking for a new car?");
    CHECK(myBoard.read(1,0,Direction::Horizontal,18) == "looking for a new ");
    
    myBoard.post(2,11,Direction::Horizontal,"ameer is wanted !!");
    CHECK(myBoard.read(8,11,Direction::Horizontal,12) == "is wanted !!");
    
    myBoard.post(3,3,Direction::Horizontal,"building man nadav 0502133322");
    CHECK(myBoard.read(22,3,Direction::Horizontal,9) == "050213332");
    
    myBoard.post(4,4,Direction::Horizontal,"");
    CHECK(myBoard.read(2,4,Direction::Horizontal,0) == "__");
    
    myBoard.post(5,5,Direction::Horizontal," ");
    CHECK(myBoard.read(5,5,Direction::Horizontal,1) == " ");
    
    myBoard.post(4,4,Direction::Horizontal,"looking for :");
    CHECK(myBoard.read(4,4,Direction::Horizontal,13) == "looking for :");
    
    myBoard.post(18,4,Direction::Horizontal,"job , call me 092311456");
    CHECK(myBoard.read(4,4,Direction::Horizontal,40) == "looking for :job , call me 092311456____");
    
    myBoard.post(0,0,Direction::Vertical,"");
    CHECK(myBoard.read(0,0,Direction::Vertical,5) == "_____");
    
    myBoard.post(100,100,Direction::Vertical,"copmuters for sale");
    CHECK(myBoard.read(0,0,Direction::Vertical,24) == "looking for a new house?");
    
    myBoard.post(100,200, ariel::Direction::Vertical, "hello world");  
    CHECK(myBoard.read(100, 200, ariel::Direction::Vertical, 11) == "hello world");
    CHECK(myBoard.read(98, 200, ariel::Direction::Vertical, 3) == "__h");
    CHECK(myBoard.read(104, 200, ariel::Direction::Vertical, 5) == "o wor");
    CHECK(myBoard.read(108, 200, ariel::Direction::Vertical, 5) == "rld__");

    myBoard.post(110,200, ariel::Direction::Horizontal, "phone number - 757-9275..."); 
    CHECK(myBoard.read(108, 200, ariel::Direction::Vertical, 6) == "__p___");
    CHECK(myBoard.read(112, 200, ariel::Direction::Vertical, 5) == "_____");
    CHECK(myBoard.read(107, 215, ariel::Direction::Vertical, 5) == "___7_");
    
    
}
