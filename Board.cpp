#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{

   Board::Board(){
       x = 2;
       y = 2;
   }

   void Board::setX(int width){
       x = width;
   }

   void Board::setY(int hight){
       y = hight;
   }

   void Board::post(unsigned int xwidth , unsigned int yhight , Direction d , string s){}

   string Board::read(unsigned int xwidth ,unsigned int yhight , Direction d , int num){
       return "reading...";
   }

   void Board::show(){}

}
