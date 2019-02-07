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