#include <iostream>
#include <sys/time.h>
using namespace std;

int binarySearch(int array[], int size, int value) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (value < array[mid]) {
      high = mid - 1;
    }
    else if (value > array[mid]) {
      low = mid + 1;
    }
    else {
      return mid;
    }
  }

  return -1;
}

int getTime() {
  struct timeval tp;
  gettimeofday(&tp, nullptr);
  return tp.tv_usec;
}

int main() {

  return 0;
}
