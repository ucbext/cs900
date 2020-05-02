#include <gtest/gtest.h>

#include "program4/word_separator.h"
#include <iostream>

TEST(WordSeparatorTest, EmptyString) {
    ASSERT_EQ("", separate_words(""));
}

TEST(WordSeparatorTest, AllUppercaseCharacters) {
    ASSERT_EQ("A B C D E F", separate_words("ABCDEF"));
}

TEST(WordSeparatorTest, SingleWord) {
    ASSERT_EQ("Watermelon", separate_words("Watermelon"));
}

TEST(WordSeparatorTest, Regular) {
    ASSERT_EQ("Stop and smell the roses", separate_words("StopAndSmellTheRoses"));
}