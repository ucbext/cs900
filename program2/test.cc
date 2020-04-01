#include <cstdio>
#include <fcntl.h>
#include <iostream>
#include <limits>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <unordered_set>

#include <gtest/gtest.h>
#include "program2/lowest_score.h"
#include "program2/is_prime.h"

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

  // call getScore
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
    int r = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/size));
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
    float r = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/size));
    scores[i] = r;
    sum += r;
  }

  float lowest = find_lowest(scores, size);
  float expected = (sum - lowest) / (size - 1);
  ASSERT_EQ(expected, calc_average(scores, size));
}

TEST(IsPrimeTest, PrimeNumbers) {
  std::unordered_set<int> primes({
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
    197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307,
    311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
    431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547,
    557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659,
    661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797,
    809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929,
    937, 941, 947, 953, 967, 971, 977, 983, 991, 997
  });

  for (int i = 2; i < 1000; i++) {
    if (primes.count(i) == 0) {
      ASSERT_FALSE(is_prime(i)) << i;
    }
    else {
      ASSERT_TRUE(is_prime(i)) << i;
    }
  }
}
