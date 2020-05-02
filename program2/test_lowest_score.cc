#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <limits>

#include <gtest/gtest.h>
#include "program2/lowest_score.h"

float call_get_score(float input) {
  // redirect stdin and stdout
  int old_stdin = dup(STDIN_FILENO);
  EXPECT_NE(-1, old_stdin) << strerror(errno);

  int old_stdout = dup(STDOUT_FILENO);
  EXPECT_NE(-1, old_stdin) << strerror(errno);

  // create pipes and redirect stdin and stdout
  int fds[] = {-1, -1};
  EXPECT_EQ(0, pipe(fds)) << strerror(errno);

  EXPECT_EQ(0, close(STDIN_FILENO)) << strerror(errno);
  EXPECT_NE(-1, dup2(fds[0], STDIN_FILENO)) << strerror(errno);

  int fd_dev_null = open("/dev/null", O_WRONLY);
  EXPECT_NE(-1, fd_dev_null);
  EXPECT_EQ(0, close(STDOUT_FILENO)) << strerror(errno);
  EXPECT_NE(-1, dup2(fd_dev_null, STDOUT_FILENO)) << strerror(errno);

  // call get_score
  dprintf(fds[1], "%f\n", input);
  float score = -1.0f;
  get_score(score);

  // restore old stdin and stdout
  EXPECT_EQ(0, close(fds[0])) << strerror(errno);
  EXPECT_EQ(0, close(fds[1])) << strerror(errno);

  EXPECT_EQ(0, close(STDIN_FILENO)) << strerror(errno);
  EXPECT_NE(-1, dup2(old_stdin, STDIN_FILENO)) << strerror(errno);
  EXPECT_EQ(0, close(old_stdin)) << strerror(errno);

  EXPECT_EQ(0, close(fd_dev_null)) << strerror(errno);
  EXPECT_EQ(0, close(STDOUT_FILENO)) << strerror(errno);
  EXPECT_NE(-1, dup2(old_stdout, STDOUT_FILENO)) << strerror(errno);
  EXPECT_EQ(0, close(old_stdout)) << strerror(errno);

  return score;
}

TEST(LowestScoreTest, GetScoreBelow0) {
  ASSERT_EQ(-1, call_get_score(-5));
}

TEST(LowestScoreTest, GetScoreAbove100) {
  ASSERT_EQ(-1, call_get_score(101));
}

TEST(LowestScoreTest, GetScoreValid) {
  for (int i = 0; i < 101; i++) {
    ASSERT_EQ(i, call_get_score(i)) << i;
  }
}

TEST(LowestScoreTest, FindLowest) {
  size_t size = 1000;
  float scores[size] = {0};

  float expected = std::numeric_limits<float>::max();
  for (unsigned int i = 0; i < size; i++) {
    int r = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / size));
    if (r < expected) {
      expected = r;
    }

    scores[i] = r;
  }

  ASSERT_EQ(expected, find_lowest(scores, size));
}

TEST(LowestScoreTest, CalcAverage) {
  float sum = 0.0f;

  size_t size = 1000;
  float scores[size] = {0};
  for (unsigned int i = 0; i < size; i++) {
    float r = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / size));
    scores[i] = r;
    sum += r;
  }

  float lowest = find_lowest(scores, size);
  float expected = (sum - lowest) / (size - 1);
  ASSERT_EQ(expected, calc_average(scores, size));
}
