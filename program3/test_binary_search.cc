#include <gtest/gtest.h>
#include <vector>

#include "program3/binary_search.h"

TEST(BinarySearchTest, SingleElement) {
  int index = binary_search({4}, 4);
  ASSERT_EQ(0, index);
}

TEST(BinarySearchTest, ValueExists) {
  int index = binary_search({4, 18, 9, -2, 44, 1, 27, 98}, 27);
  ASSERT_EQ(6, index);
}

TEST(BinarySearchTest, ValueMissing) {
  int index = binary_search({4, 18, 9, -2, 44, 1, 27, 98}, 10);
  ASSERT_EQ(-1, index);
}
