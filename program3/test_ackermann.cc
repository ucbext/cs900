#include <gtest/gtest.h>
#include "program3/ackermann.h"

TEST(AckermannTest, Regular) {
    ASSERT_EQ(1, ackermann(0, 0));
    ASSERT_EQ(2, ackermann(0, 1));
    ASSERT_EQ(3, ackermann(1, 1));
    ASSERT_EQ(4, ackermann(1, 2));
    ASSERT_EQ(5, ackermann(1, 3));
    ASSERT_EQ(7, ackermann(2, 2));
    ASSERT_EQ(29, ackermann(3, 2));
}
