#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


TEST_CASE("Good snowman hats") {
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(21114411) == string("  ___  \n ..... \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(31114411) == string("   _   \n  /_\\  \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(41114411) == string("  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) "));
    /* Add more checks here */
}

TEST_CASE("Good snowman hands")
{
    // left arms 
    CHECK(snowman(11111411) == string(" _===_ \n (.,.) \n<( : ) \n ( : ) "));
    CHECK(snowman(21112411) == string("  ___  \n ..... \n\\(.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(31113411) == string("   _   \n  /_\\  \n (.,.) \n/( : ) \n ( : ) "));
    CHECK(snowman(41114411) == string("  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) "));
    // right arms 
    CHECK(snowman(11114111) == string(" _===_ \n (.,.) \n ( : )>\n ( : ) "));
    CHECK(snowman(21114211) == string("  ___  \n ..... \n (.,.)/\n ( : ) \n ( : ) "));
    CHECK(snowman(31114311) == string("   _   \n  /_\\  \n (.,.) \n ( : )\\\n ( : ) "));
    CHECK(snowman(41114411) == string("  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) "));
}
TEST_CASE("Good snowman eyes")
{
    // left eyes 
    CHECK(snowman(11111411) == string(" _===_ \n (.,.) \n<( : ) \n ( : ) "));
    CHECK(snowman(21212411) == string("  ___  \n ..... \n\\(o,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(31313411) == string("   _   \n  /_\\  \n (O,.) \n/( : ) \n ( : ) "));
    CHECK(snowman(41414411) == string("  ___  \n (_*_) \n (-,.) \n ( : ) \n ( : ) "));
    // right eyes 
    CHECK(snowman(11114111) == string(" _===_ \n (.,.) \n ( : )>\n ( : ) "));
    CHECK(snowman(21124211) == string("  ___  \n ..... \n (.,o)/\n ( : ) \n ( : ) "));
    CHECK(snowman(31134311) == string("   _   \n  /_\\  \n (.,O) \n ( : )\\\n ( : ) "));
    CHECK(snowman(41144411) == string("  ___  \n (_*_) \n (.,-) \n ( : ) \n ( : ) "));
}
TEST_CASE("Good snowman noses")
{
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(22114411) == string("  ___  \n ..... \n (...) \n ( : ) \n ( : ) "));
    CHECK(snowman(33114411) == string("   _   \n  /_\\  \n (._.) \n ( : ) \n ( : ) "));
    CHECK(snowman(44114411) == string("  ___  \n (_*_) \n (. .) \n ( : ) \n ( : ) "));
}
TEST_CASE("Good snowman torsos")
{
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(22114421) == string("  ___  \n ..... \n (...) \n (] [) \n ( : ) "));
    CHECK(snowman(33114431) == string("   _   \n  /_\\  \n (._.) \n (> <) \n ( : ) "));
    CHECK(snowman(44114441) == string("  ___  \n (_*_) \n (. .) \n (   ) \n ( : ) "));
}
TEST_CASE("Good snowman bases")
{
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    CHECK(snowman(22114422) == string("  ___  \n ..... \n (...) \n (] [) \n (\" \") "));
    CHECK(snowman(33114433) == string("   _   \n  /_\\  \n (._.) \n (> <) \n (___) "));
    CHECK(snowman(44114444) == string("  ___  \n (_*_) \n (. .) \n (   ) \n (   ) "));
}

TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
    	
    CHECK_THROWS(snowman(01111111));
    CHECK_THROWS(snowman(10111111));
    CHECK_THROWS(snowman(11011111));
    CHECK_THROWS(snowman(11101111));
    CHECK_THROWS(snowman(11110111));
    CHECK_THROWS(snowman(11111011));
    CHECK_THROWS(snowman(11111101));
    CHECK_THROWS(snowman(11111110));

    /* Add more checks here */
}


/* Add more test cases here */
