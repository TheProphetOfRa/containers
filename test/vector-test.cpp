#include "gtest/gtest.h"
#include "vector.hpp"

#pragma mark - Constructors

TEST(Constructors, empty)
{
    containers::Vector<int> v;
    
    ASSERT_EQ(v.size(), 0);
    ASSERT_EQ(v.capacity(), 128);
}

TEST(Constructors, size)
{
    containers::Vector<int> v(128);
    
    ASSERT_EQ(v.size(), 128);
    EXPECT_EQ(v.capacity(), 128);
    
    for (int i = 0 ; i < v.capacity() ; ++i)
    {
        EXPECT_EQ(v[i], 0);
    }
}

TEST(Constructors, sizeInitial)
{
    containers::Vector<int> v(128, 5);
    
    ASSERT_EQ(v.size(), 128);
    EXPECT_EQ(v.capacity(), 128);
    
    for (int i = 0 ; i < v.capacity() ; ++i)
    {
        ASSERT_EQ(v[i], 5);
    }
}

TEST(Constructors, copy)
{
    containers::Vector<int> init(200, 5);
    
    ASSERT_EQ(init.size(), 200);
    EXPECT_EQ(init.capacity(), 256);
    
    for (int i = 0 ; i < init.size() ; ++i)
    {
        ASSERT_EQ(init[i], 5);
    }
    
    containers::Vector<int> v(init);
    
    ASSERT_EQ(v.size(), init.size());
    ASSERT_EQ(v.capacity(), init.capacity());
    
    for (int i = 0 ; i < init.size() ; ++i)
    {
        ASSERT_EQ(v[i], init[i]) << "Index is " << i;
    }
}

#pragma mark - IntegrityTest

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
