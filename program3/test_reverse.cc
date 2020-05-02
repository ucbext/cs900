#include <gtest/gtest.h>
#include <sstream>
#include <vector>

#include "program3/reverse.h"

std::string print_array(const std::vector<int>& data) {
  std::ostringstream oss;

  oss << "[";
  for (size_t i = 0; i < data.size(); i++) {
    oss << data[i];

    if (i != data.size() - 1) {
      oss << ", ";
    }
  }
  oss << "]";

  return std::move(oss.str());
}

TEST(ReverseTest, SingleElement) {
  std::vector<int> expected = {4};
  std::vector<int> actual = reverse({4});
  ASSERT_EQ(expected[0], actual[0]);
}

TEST(ReverseTest, TwoElements) {
  std::vector<int> expected = {8, 4};
  std::vector<int> actual = reverse({4, 8});

  for (size_t i = 0; i < actual.size(); i++) {
    ASSERT_EQ(expected[i], actual[i]) << "expected: " << print_array(expected) << " "
                                      << "actual: " << print_array(actual);
  }
}

TEST(ReverseTest, Regular) {
  std::vector<int> expected = {98, 27, 1, 44, -2, 9, 18, 4};
  std::vector<int> actual = reverse({4, 18, 9, -2, 44, 1, 27, 98});

  for (size_t i = 0; i < actual.size(); i++) {
    ASSERT_EQ(expected[i], actual[i]) << "expected: " << print_array(expected) << " "
                                      << "actual: " << print_array(actual);
  }
}
