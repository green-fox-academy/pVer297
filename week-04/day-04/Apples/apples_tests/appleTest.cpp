//
// Created by Egri Zoltán on 2019. 02. 07..
//

#include <gtest/gtest.h>
#include "apple.h"

TEST(AppleTest, trueTest)
{
    ASSERT_EQ(getApple(), "apple");
}

TEST(AppleTest, falseTest)
{
    ASSERT_NE(getApple(), "pear");
}

TEST(SumTest, emptyList)
{
    std::vector<int> nums = {};
    int sumOfNums = sum(nums);
    ASSERT_EQ(sumOfNums, 0);
}

TEST(SumTest, oneElement)
{
    std::vector<int> nums = {1};
    int sumOfNums = sum(nums);
    ASSERT_EQ(sumOfNums, 1);
}

TEST(SumTest, multipleElements)
{
    std::vector<int> nums = {1,2,3,4,5};
    int sumOfNums = sum(nums);
    ASSERT_EQ(sumOfNums, 15);
}

TEST(SumTest, negativeNumbers){
    std::vector<int> nums = {-5,-8,10,-10,3};
    int sumOfNums = sum(nums);
    ASSERT_EQ(sumOfNums, -10);
}