#pragma once

#include "Direction.hpp"
using ariel::Direction;

#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
    class Board
    {
    private:
        unsigned int top, bottom, left, right;
        vector<vector<char>> messagesBoard;

    public:
        void post(const unsigned int row, const unsigned int column, Direction, const string& message);
        string read(const unsigned int row, const unsigned int column, Direction, const unsigned int length);
        void show();
    };
}