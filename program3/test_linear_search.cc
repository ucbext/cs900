#include <gtest/gtest.h>

#include "program3/linear_search.h"

TEST(LinearSearchTest, SingleElement) {
    int index = linear_search({4}, 4);
    ASSERT_EQ(0, index);
}

TEST(LinearSearchTest, ValueExists) {
    int index = linear_search({4, 18, 9, -2, 44, 1, 27, 98}, 27);
    ASSERT_EQ(6, index);
}

TEST(LinearSearchTest, ValueMissing) {
    int index = linear_search({4, 18, 9, -2, 44, 1, 27, 98}, 10);
    ASSERT_EQ(-1, index);
}
