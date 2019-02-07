#include <gtest/gtest.h>
#include "anagram.h"

TEST(AnagramTest, testSame){
    ASSERT_EQ(isAnagram("apple","apple"), true);
}

TEST(AnagramTest, testEmpty){
    ASSERT_EQ(isAnagram("apple",""), false);
}

TEST(AnagramTest, testLonger){
    ASSERT_EQ(isAnagram("apple","appple"), false);
}

TEST(AnagramTest, testShorter){
    ASSERT_EQ(isAnagram("apple","aple"), false);
}

TEST(AnagramTest, testReverse){
    ASSERT_EQ(isAnagram("apple","elppa"), true);
}

TEST(AnagramTest, testChars){ //testing matching char numbers but not matching chars
    ASSERT_EQ(isAnagram("apple","aplle"), false);
}