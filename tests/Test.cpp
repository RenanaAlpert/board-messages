#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

static Board b;

TEST_CASE("bad input - empty post")
{
    CHECK_THROWS(b.post(3, 1, Direction::Vertical, ""));
}

TEST_CASE("good test - Horizontal")
{
    b.post(0, 0, Direction::Horizontal, "abcd");
    CHECK(b.read(0, 0, Direction::Horizontal, 4) == "abcd");
}

TEST_CASE("good test - Vertical")
{
    b.post(1, 4, Direction::Vertical, "xyz");
    CHECK(b.read(1, 4, Direction::Vertical, 3) == "xyz");
}

TEST_CASE("good test - overriding T")
{
    b.post(1, 3, Direction::Horizontal, "over");
    CHECK(b.read(1, 4, Direction::Vertical, 3) == "vyz");
}

TEST_CASE("good test - overriding -|")
{
    b.post(2, 3, Direction::Vertical, "vertical");
    b.post(4, 0, Direction::Horizontal, "soup");
    CHECK(b.read(2, 3, Direction::Vertical, 8) == "veptical");
}

TEST_CASE("good test - overriding +"){
    b.post(5, 6, Direction::Vertical, "dog");
    CHECK(b.read(5, 6, Direction::Vertical, 3) == "dog");
    b.post(6, 5, Direction::Horizontal, "cat");
    CHECK(b.read(5, 6, Direction::Vertical, 3) == "dag");
}

TEST_CASE("good test - overriding long word with short word"){
    CHECK(b.read(0, 3, Direction::Vertical, 4) == "dove");
    b.post(0, 3, Direction::Vertical, "food");
    CHECK(b.read(0, 3, Direction::Vertical, 4) == "food");
    CHECK(b.read(0, 3, Direction::Vertical, 10) == "foodptical");
}

TEST_CASE("good test - overriding short word with long word"){
    CHECK(b.read(5, 6, Direction::Vertical, 3) == "dag");
    b.post(3, 6, Direction::Vertical, "system");
    CHECK(b.read(5, 6, Direction::Vertical, 3) == "ste");
    CHECK(b.read(3, 6, Direction::Vertical, 6) == "system");
}

TEST_CASE("good test - overriding 2 word"){
    CHECK(b.read(0, 0, Direction::Horizontal, 4) == "abcf");
    CHECK(b.read(0, 4, Direction::Horizontal, 4) == "soup");
    b.post(0, 0, Direction::Vertical, "computer");
    CHECK(b.read(0, 0, Direction::Horizontal, 4) == "cbcf");
    CHECK(b.read(0, 4, Direction::Horizontal, 4) == "uoup");
}

TEST_CASE("good test - without text")
{
    CHECK(b.read(0, 2, Direction::Horizontal, 4) == "cd__");
    CHECK(b.read(0, 4, Direction::Vertical, 3) == "_vy");
    CHECK(b.read(1, 2, Direction::Horizontal, 7) == "_over_");
    CHECK(b.read(5, 1, Direction::Vertical, 3) == "___");
}

TEST_CASE("good test - reading 0 chars"){
    CHECK(b.read(5, 1, Direction::Vertical, 0) == "");
    CHECK(b.read(1, 3, Direction::Horizontal, 0) == "");
}

/*
1. read 0 == ""
2. short word over long word -> get a mash of both. vertical & horizontal
3. long word over short word -> get long word. vertical & horizontal
*/