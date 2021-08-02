#pragma once

#include "Direction.hpp"
using ariel::Direction;

#include <vector>
#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

namespace ariel
{
    class Board
    {
    private:
        unsigned int top, bottom, left, right;
        unordered_map<string, char> messagesBoard;
    public:
        Board(): top(UINT_MAX), bottom(0), left(UINT_MAX), right(0){};
        void post(unsigned int row, unsigned int column, Direction, const string& message);
        string read(const unsigned int row, const unsigned int column, Direction, const unsigned int length);
        void show();
    };
}