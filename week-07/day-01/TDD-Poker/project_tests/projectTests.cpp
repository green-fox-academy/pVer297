#include "gtest/gtest.h"

extern "C" {
#include "project.h"
}

TEST(EnvTest, trueCheck)
{
    EXPECT_EQ(0, 0);
    EXPECT_GT(1, 0);
    EXPECT_LT('a', 'z');
    EXPECT_TRUE(1);
    EXPECT_FALSE(0);
}

TEST(CardTest, HighCardFirst)
{
    card_t firstHand[] = {{_K,H},{_9,D},{_5,S},{_3,C},{_2,D}};
    card_t secondHand[] = {{_K,C},{_8,H},{_4,S},{_3,C},{_2,H}};
    EXPECT_STREQ("First wins! - (High card: 9)", checkHand(firstHand, secondHand));
}

TEST(CardTest, HighCardSecond)
{
    card_t firstHand[] = {{_K,H},{_8,D},{_5,S},{_3,C},{_2,D}};
    card_t secondHand[] = {{_K,C},{_9,H},{_4,S},{_3,C},{_2,H}};
    EXPECT_STREQ("Second wins! - (High card: 9)", checkHand(firstHand, secondHand));
}

TEST(CardTest, SortTest){
    card_t firstHand[] = {{_2,H},{_3,D},{_5,S},{_8,C},{_K,D}};
    card_t secondHand[] = {{_2,C},{_3,H},{_4,S},{_9,C},{_K,H}};
    EXPECT_STREQ("Second wins! - (High card: 9)", checkHand(firstHand, secondHand));
}

TEST(CardTest, Tie){
    card_t firstHand[] = {{_2,H},{_3,D},{_5,S},{_8,C},{_K,D}};
    card_t secondHand[] = {{_2,H},{_3,D},{_5,S},{_8,C},{_K,D}};
    EXPECT_STREQ("Tie", checkHand(firstHand, secondHand));
}

TEST(CardTest, HighCardByValue){
    card_t firstHand[] = {{_2,H},{_K,D},{_5,S},{_8,C},{_4,D}};
    card_t secondHand[] = {{_2,H},{_3,D},{_5,S},{_8,C},{_K,D}};
    EXPECT_STREQ("First wins! - (High card: 4)", checkHand(firstHand, secondHand));
}