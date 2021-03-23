#include <iostream>
using namespace std;
#include "Direction.hpp"
#include <stdexcept>

namespace ariel{

class Board{
    int x = 2;
    int y = 2;

public:

Board();
void setX(int width);
void setY(int hight);
void post(unsigned int xwidth ,unsigned int yhight , ariel::Direction d , string s);
string read(unsigned int xwidth ,unsigned int yhight , ariel::Direction d , int num);
void show();
};

}