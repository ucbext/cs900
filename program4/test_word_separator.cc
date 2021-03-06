#include <gtest/gtest.h>

#include <iostream>
#include "program4/word_separator.h"

TEST(WordSeparatorTest, EmptyString) {
  ASSERT_EQ("", separate_words(""));
}

TEST(WordSeparatorTest, OnlySpaces) {
  ASSERT_EQ("", separate_words("   "));
}

TEST(WordSeparatorTest, AllUppercaseCharacters) {
  ASSERT_EQ("A b c d e f", separate_words("ABCDEF"));
}

TEST(WordSeparatorTest, SingleWord) {
  ASSERT_EQ("Watermelon", separate_words("Watermelon"));
}

TEST(WordSeparatorTest, Regular) {
  ASSERT_EQ("Stop and smell the roses", separate_words("StopAndSmellTheRoses"));
}

TEST(WordSeparatorTest, LeadingSpaces) {
  ASSERT_EQ("Foo", separate_words("  Foo"));
}

TEST(WordSeparatorTest, TrailingSpaces) {
  ASSERT_EQ("Foo", separate_words("Foo  "));
}