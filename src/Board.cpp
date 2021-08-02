#include "Board.hpp"
using namespace ariel;

void Board::post(unsigned int row, unsigned int column, Direction d, const string &message)
{
    if (message.empty() || message.length() == 0)
    {
        return;
    }

    if (row < top || top == UINT_MAX)
    {
        top = row;
    }
    if (row > bottom || bottom == 0)
    {
        bottom = row;
    }
    if (column < left || left == UINT_MAX)
    {
        left = column;
    }
    if (column > right || right == 0)
    {
        right = column;
    }

    string key;
    if (d == Direction::Horizontal)
    {
        for (size_t i = 0; i < message.length(); i++, column++)
        {
            key = to_string(row) + '.' + to_string(column);
            messagesBoard[key] = message.at(i);
        }
    }
    else if (d == Direction::Vertical)
    {
        for (size_t i = 0; i < message.length(); i++, row++)
        {
            key = to_string(row) + '.' + to_string(column);
            messagesBoard[key] = message.at(i);
        }
    }
}

string Board::read(unsigned int row, unsigned int column, Direction d, const unsigned int length)
{
    if (length == 0)
    {
        return "";
    }

    string message;
    string key;
    if (d == Direction::Horizontal)
    {
        for (size_t i = 0; i < length; i++, column++)
        {
            key = to_string(row) + '.' + to_string(column);
            try
            {
                message += messagesBoard.at(key);
            }
            catch (const std::out_of_range)
            {
                message += '_';
            }
        }
    }
    else if (d == Direction::Vertical)
    {
        for (size_t i = 0; i < length; i++, row++)
        {
            key = to_string(row) + '.' + to_string(column);
            try
            {
                message += messagesBoard.at(key);
            }
            catch (const std::out_of_range)
            {
                message += '_';
            }
        }
    }

    return message;
}

void Board::show()
{
    unsigned int t = top;
    unsigned int l = left;
    string key;
    for (; t < bottom; t++)
    {
        for (unsigned int i = left; i < right; i++, l++)
        {
            key = to_string(t) + '.' + to_string(l);
            try
            {
                cout << messagesBoard.at(key);
            }
            catch (const std::out_of_range)
            {
                cout << '_';
            }
        }
        cout << endl;
    }
}
