#include <gtest/gtest.h>
#include <sstream>

#include "program3/reverse.h"

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
