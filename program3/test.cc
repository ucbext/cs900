#include <gtest/gtest.h>
#include <sstream>

#include "program3/ackermann.h"
#include "program3/reverse.h"
#include "program3/linear_search.h"
#include "program3/binary_search.h"

std::string print_array(int array[], int size) {
  std::ostringstream oss;

  oss << "[";
  for (int i = 0; i < size; i++) {
    oss << array[i];

    if (i != size - 1) {
      oss << ", ";
    }
  }
  oss << "]";

  return std::move(oss.str());
}

TEST(ReverseTest, SingleElement) {
  int array[] = {4};
  int size = sizeof(array) / sizeof(int);
  int expected[] = {4};
  int* actual = reverse(array, size);
  ASSERT_EQ(expected[0], actual[0]);
}

TEST(ReverseTest, TwoElements) {
  int array[] = {4, 8};
  int size = sizeof(array) / sizeof(int);
  int expected[] = {8, 4};
  int* actual = reverse(array, size);

  for (int i = 0; i < size; i++) {
    ASSERT_EQ(expected[i], actual[i])
      << "expected: " << print_array(expected, size) << " "
      << "actual: " << print_array(actual, size);
  }
}

TEST(ReverseTest, Regular) {
  int array[] = {4, 18, 9, -2, 44, 1, 27, 98};
  int size = sizeof(array) / sizeof(int);

  int expected[] = {98, 27, 1, 44, -2, 9, 18, 4};
  int* actual = reverse(array, size);

  for (int i = 0; i < size; i++) {
    ASSERT_EQ(expected[i], actual[i])
      << "expected: " << print_array(expected, size) << " "
      << "actual: " << print_array(actual, size);
  }
}

TEST(AckermannTest, Regular) {
  ASSERT_EQ(1, ackermann(0, 0));
  ASSERT_EQ(2, ackermann(0, 1));
  ASSERT_EQ(3, ackermann(1, 1));
  ASSERT_EQ(4, ackermann(1, 2));
  ASSERT_EQ(5, ackermann(1, 3));
  ASSERT_EQ(7, ackermann(2, 2));
  ASSERT_EQ(29, ackermann(3, 2));
}

TEST(LinearSearchTest, SingleElement) {
  int array[] = {4};
  int size = sizeof(array) / sizeof(int);
  int index = linear_search(array, size, 4);
  ASSERT_EQ(0, index);
}

TEST(LinearSearchTest, ValueExists) {
  int array[] = {4, 18, 9, -2, 44, 1, 27, 98};
  int size = sizeof(array) / sizeof(int);
  int index = linear_search(array, size, 27);
  ASSERT_EQ(6, index);
}

TEST(LinearSearchTest, ValueMissing) {
  int array[] = {4, 18, 9, -2, 44, 1, 27, 98};
  int size = sizeof(array) / sizeof(int);
  int index = linear_search(array, size, 10);
  ASSERT_EQ(-1, index);
}

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
