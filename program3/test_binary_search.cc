#include <gtest/gtest.h>

#include "program3/binary_search.h"

TEST(BinarySearchTest, SingleElement) {
  int array[] = {4};
  int size = sizeof(array) / sizeof(int);
  int index = binary_search(array, size, 4);
  ASSERT_EQ(0, index);
}

TEST(BinarySearchTest, ValueExists) {
  int array[] = {4, 18, 9, -2, 44, 1, 27, 98};
  int size = sizeof(array) / sizeof(int);
  int index = binary_search(array, size, 27);
  ASSERT_EQ(6, index);
}

TEST(BinarySearchTest, ValueMissing) {
  int array[] = {4, 18, 9, -2, 44, 1, 27, 98};
  int size = sizeof(array) / sizeof(int);
  int index = binary_search(array, size, 10);
  ASSERT_EQ(-1, index);
}
