#include <gtest/gtest.h>

#include "program5/dynamic_array.h"

TEST(DynamicArrayTest, DefaultConstructor) {
  DynamicArray<int> array;
  ASSERT_EQ(0, array.get_size());
  ASSERT_EQ(0, array.get_capacity());
}

TEST(DynamicArrayTest, CapacityConstructor) {
  size_t size = 10;
  DynamicArray<int> array(size);
  ASSERT_EQ(size, array.get_size());
  ASSERT_EQ(size, array.get_capacity());
}

TEST(DynamicArrayTest, At) {

}