// Author - Dvir Sadon

#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <iostream>

using namespace std;
using namespace itertools;

TEST_CASE("Test range") // 10
{
    int c = 0;
    for(int num : range(0,10))
    {
        CHECK(c == num);
        ++c;
    }
}

TEST_CASE("Test accumulate") // 25
{

}

TEST_CASE("Test filterfalse") // 25
{

}

TEST_CASE("Test compress") // 25
{
 
}

TEST_CASE("Test Exceptions") // 15