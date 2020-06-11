// Author - Dvir Sadon

#include "doctest.h"
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"
#include "compress.hpp"
#include <iostream>

using namespace std;
using namespace itertools;

TEST_CASE("Test range") // 30
{
    int c = 0;
    for(int num : range(0, 10))
    {
        CHECK(c == num);
        ++c;
    }

    c = -5;
    for(int num : range(-5, 5))
    {
        CHECK(c == num);
        ++c;
    }

    c = -10;
    for(int num : range(-10, 0))
    {
        CHECK(c == num);
        ++c;
    }
}

TEST_CASE("Test accumulate") // 35
{
    int c[] = {5, 5+6, 5+6+7, 5+6+7+8};
    int i = 0;
    for(int num : accumulate(range(5, 9)))
    {
        CHECK(c[i] == num);
        ++i;
    }

    int ce[] = {0, 1, 3, 6, 10, 15, 21, 28, 36, 45};
    i = 0;
    for(int num2 : accumulate(range(0, 10)))
    {
        CHECK(ce[i] == num2);
        ++i;
    }

    int che[] = {-10, -19, -27, -34, -40, -45, -49, -52, -54, -55};
    i = 0;
    for(int num3 : accumulate(range(-10, 0)))
    {
        CHECK(che[i] == num3);
        ++i;
    }

    int chec[] = {-10, -1, 7, 14, 20, 25, 29, 32, 34, 35};
    i = 0;
    for(int num : accumulate(range(-10, 0), [](int x, int y){return x-y;}))
    {
        CHECK(chec[i] == num);
        ++i;
    }
}

TEST_CASE("Test filterfalse") // 25
{

}

TEST_CASE("Test compress") // 25
{
 
}

TEST_CASE("Test Exceptions") // 15
{

}