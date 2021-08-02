#include "Board.hpp"
using namespace ariel;

void Board::post(const unsigned int row, const unsigned int column, Direction d, const string& message){
    this->left = row;
    cout << "post" << endl;
}

string Board::read(const unsigned int row, const unsigned int column, Direction d, const unsigned int length){
    this->bottom = column;
    return "read";
}

void Board::show(){
    this->top = 0;
    cout << "show" << endl;
}
