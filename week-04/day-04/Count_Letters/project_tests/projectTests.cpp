#include <gtest/gtest.h>
#include "project.h"

TEST(CountCharTest, correctTest){
    std::map<char,int> testCase;
    testCase.insert(std::make_pair('a',1));
    testCase.insert(std::make_pair('p',2));
    testCase.insert(std::make_pair('l',1));
    testCase.insert(std::make_pair('e',1));

    ASSERT_EQ(countLetters("apple"),testCase);
}

TEST(CountCharTest, emptyInput){
    std::map<char,int> testCase;
    testCase.insert(std::make_pair('a',1));
    testCase.insert(std::make_pair('p',2));
    testCase.insert(std::make_pair('l',1));
    testCase.insert(std::make_pair('e',1));

    ASSERT_NE(countLetters(""),testCase);
}

TEST(CountCharTest, everythingEmpty){
    std::map<char,int> testCase;

    ASSERT_EQ(countLetters(""),testCase);
}

TEST(CountCharTest, incorrectTest){
    std::map<char,int> testCase;
    testCase.insert(std::make_pair('a',1));
    testCase.insert(std::make_pair('p',2));
    testCase.insert(std::make_pair('l',1));
    testCase.insert(std::make_pair('e',1));

    ASSERT_NE(countLetters("potato"),testCase);
}