#include <gtest/gtest.h>

#include "program4/password_verification.h"

TEST(PasswordVerificationTest, HasSixCharacters) {
  ASSERT_FALSE(has_six_chars(""));
  ASSERT_FALSE(has_six_chars("a"));
  ASSERT_FALSE(has_six_chars("ab"));
  ASSERT_FALSE(has_six_chars("abc"));
  ASSERT_FALSE(has_six_chars("abcd"));
  ASSERT_FALSE(has_six_chars("abcde"));
  ASSERT_TRUE(has_six_chars("abcdef"));
}

TEST(PasswordVerificationTest, HasUppercase) {
  ASSERT_FALSE(has_uppercase("foo"));
  ASSERT_TRUE(has_uppercase("Foo"));
  ASSERT_TRUE(has_uppercase("fOo"));
  ASSERT_TRUE(has_uppercase("foO"));
}

TEST(PasswordVerificationTest, HasLowercase) {
  ASSERT_FALSE(has_lowercase("FOO"));
  ASSERT_TRUE(has_lowercase("fOO"));
  ASSERT_TRUE(has_lowercase("FoO"));
  ASSERT_TRUE(has_lowercase("FOo"));
}

TEST(PasswordVerificationTest, HasDigit) {
  ASSERT_FALSE(has_digit("foo"));
  ASSERT_TRUE(has_digit("1foo"));
  ASSERT_TRUE(has_digit("f1oo"));
  ASSERT_TRUE(has_digit("fo1o"));
  ASSERT_TRUE(has_digit("foo1"));
}