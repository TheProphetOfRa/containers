#include "gtest/gtest.h"
#include "vector.hpp"

#pragma mark - Constructors

TEST(VectorConstructor, empty)
{
    containers::Vector<int> v;
    
    ASSERT_EQ(v.size(), 0);
    ASSERT_EQ(v.capacity(), 128);
}

TEST(VectorConstructor, size)
{
    containers::Vector<int> v(128);
    
    ASSERT_EQ(v.size(), 128);
    EXPECT_EQ(v.capacity(), 128);
    
    for (int i = 0 ; i < v.capacity() ; ++i)
    {
        EXPECT_EQ(v[i], 0);
    }
}

TEST(VectorConstructor, sizeInitial)
{
    containers::Vector<int> v(128, 5);
    
    ASSERT_EQ(v.size(), 128);
    EXPECT_EQ(v.capacity(), 128);
    
    for (int i = 0 ; i < v.capacity() ; ++i)
    {
        ASSERT_EQ(v[i], 5);
    }
}

TEST(VectorConstructor, copy)
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

#pragma mark - Capacity

TEST(VectorCapacity, reserve)
{
    containers::Vector<int> v;
    v.reserve(1000);
    
    ASSERT_EQ(v.capacity(), 1000);
    ASSERT_EQ(v.size(), 0);
}

TEST(VectorCapacity, upSize)
{
    containers::Vector<int> v(100, 5);
    
    ASSERT_EQ(v.size(), 100);
    
    for (int i = 0 ; i < 100 ; ++i)
    {
        ASSERT_EQ(v[i], 5);
    }
    
    v.resize(200);
    
    ASSERT_EQ(v.size(), 200);
    
    for (int i = 0 ; i < 200 ; ++i)
    {
        ASSERT_EQ(v[i], i < 100 ? 5 : 0);
    }
    
    v.resize(300, 3);
    
    ASSERT_EQ(v.size(), 300);
    
    for (int i = 0 ; i < 300 ; ++i)
    {
        if (i < 100)
            ASSERT_EQ(v[i], 5);
        else if (i < 200)
            ASSERT_EQ(v[i], 0);
        else
            ASSERT_EQ(v[i], 3);
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
