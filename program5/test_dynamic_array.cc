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
  ASSERT_EQ(0, array.get_size());
  ASSERT_EQ(size, array.get_capacity());
}

TEST(DynamicArrayTest, At) {
  DynamicArray<int> array(2);
  array.push_back(10);
  array.push_back(20);
  ASSERT_EQ(10, array.at(0));
  ASSERT_EQ(20, array.at(1));
}

TEST(DynamicArrayTest, AtIndexOutOfBounds) {
  DynamicArray<int> array(2);
  ASSERT_ANY_THROW(array.at(2));
}

TEST(DynamicArrayTest, GetFirst) {
  DynamicArray<int> array(2);
  array.push_back(10);
  array.push_back(20);
  ASSERT_EQ(10, array.get_first());
}

TEST(DynamicArrayTest, GetFirstEmpty) {
  DynamicArray<int> array(2);
  ASSERT_ANY_THROW(array.get_first());
}

TEST(DynamicArrayTest, GetLast) {
  DynamicArray<int> array(2);
  array.push_back(10);
  array.push_back(20);
  ASSERT_EQ(20, array.get_last());
  array.pop_back();
  ASSERT_EQ(10, array.get_last());
}

TEST(DynamicArrayTest, GetLastEmpty) {
  DynamicArray<int> array(2);
  ASSERT_ANY_THROW(array.get_last());
}

TEST(DynamicArrayTest, IsEmpty) {
  DynamicArray<int> array(2);
  ASSERT_TRUE(array.is_empty());
  array.push_back(10);
  ASSERT_FALSE(array.is_empty());
  array.pop_back();
  ASSERT_TRUE(array.is_empty());
}

TEST(DynamicArrayTest, GetSize) {
  DynamicArray<int> array(2);
  ASSERT_EQ(0, array.get_size());
  array.push_back(10);
  ASSERT_EQ(1, array.get_size());
  array.pop_back();
  ASSERT_EQ(0, array.get_size());
}

TEST(DynamicArrayTest, GetCapacity) {
  DynamicArray<int> array;
  ASSERT_EQ(0, array.get_capacity());
  array.push_back(10);
}

TEST(DynamicArrayTest, ShrinkEmpty) {
  DynamicArray<int> array;
  array.shrink();
  ASSERT_EQ(0, array.get_capacity());
  ASSERT_EQ(0, array.get_size());
}

TEST(DynamicArrayTest, Shrink) {
  DynamicArray<int> array;

  array.push_back(10);
  ASSERT_EQ(3, array.get_capacity());
  ASSERT_EQ(1, array.get_size());

  array.shrink();
  ASSERT_EQ(1, array.get_capacity());
  ASSERT_EQ(1, array.get_size());

  ASSERT_EQ(10, array.at(0));
}

TEST(DynamicArrayTest, ShrinkSameSizeCapacity) {
  DynamicArray<int> array;
  array.push_back(10);
  array.push_back(20);
  array.push_back(30);

  ASSERT_EQ(3, array.get_capacity());
  ASSERT_EQ(3, array.get_size());

  array.shrink();

  ASSERT_EQ(3, array.get_capacity());
  ASSERT_EQ(3, array.get_size());

  ASSERT_EQ(10, array.at(0));
  ASSERT_EQ(20, array.at(1));
  ASSERT_EQ(30, array.at(2));
}

TEST(DynamicArrayTest, Clear) {
  DynamicArray<int> array;
  array.push_back(10);
  array.push_back(20);
  array.push_back(30);

  ASSERT_EQ(3, array.get_capacity());
  ASSERT_EQ(3, array.get_size());

  array.clear();

  ASSERT_EQ(0, array.get_capacity());
  ASSERT_EQ(0, array.get_size());
}

TEST(DynamicArrayTest, PushBackTriple) {
  DynamicArray<int> array;
  ASSERT_EQ(0, array.get_capacity());

  array.push_back(10);
  array.push_back(20);
  array.push_back(30);
  ASSERT_EQ(3, array.get_capacity());
  ASSERT_EQ(3, array.get_size());

  array.push_back(40);
  ASSERT_EQ(4, array.get_size());
  ASSERT_EQ(9, array.get_capacity());
}

TEST(DynamicArrayTest, PopBack) {
  DynamicArray<int> array;
  array.push_back(10);
  array.push_back(20);
  array.push_back(30);
  array.push_back(40);

  ASSERT_EQ(4, array.get_size());
  ASSERT_EQ(9, array.get_capacity());

  array.pop_back();

  ASSERT_EQ(30, array.get_last());
  ASSERT_EQ(3, array.get_size());
  ASSERT_EQ(9, array.get_capacity());
}