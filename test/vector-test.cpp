#include "gtest/gtest.h"
#include "vector.hpp"

TEST(integrityTest, smallTest)
{
    containers::Vector<int> v;
    for (int i = 0 ; i < 128 ; ++i)
    {
        v.push_back(i);
    }
    
    int check = 0;
    for(containers::Vector<int>::iterator it = v.begin() ; it != v.end() ; ++it)
    {
        ASSERT_EQ(*it, check);
        ++check;
    }
}

TEST(integrityTest, growTest)
{
    containers::Vector<int> v;
    for (int i = 0 ; i < 2000 ; ++i)
    {
        v.push_back(i);
    }
    
    int check = 0;
    for(containers::Vector<int>::iterator it = v.begin() ; it != v.end() ; ++it)
    {
        ASSERT_EQ(*it, check);
        ++check;
    }
}
