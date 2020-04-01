Program 3
---------
Program 3 covers concepts found in the following chapters:

- Chapter 8: Searching and sorting arrays
- Chapter 9: Pointers
- Chapter 19: Recursion

Before you begin, you may want to go back and review these chapters to ensure you understand them
fully. To get you started, each program file along with the appropriate Bazel configuration has
already been setup for you in the `program3` directory. You simply need to fill out each file with
the appropriate code.

In order for tests to pass and ensure that you get the proper grade that you deserve, you must
ensure that your output case-sensitively matches the output that the tests expect.

Reverse
-------
Write a function, `reverse`, that accepts an integer array and the array's size as arguments. The
function should create a copy of the array, except that the element values should be reversed in the
copy. The function should return a pointer to the new array.

The files you will need for this exercise are:

- `program3/reverse.cc`

Ackermann
---------
Ackermann's Function is a recursive mathematical algorithm that can be used to test how well a
computer performs recursion. Write a function `ackermann(m, n)` that solves Ackermann's Function.
Use the following logic in your function:

    If m = 0 then return n + 1
    If n = 0 then return A(m - 1, 1)
    Otherwise, return A(m - 1, A(m, n - 1))

The files you will need for this exercise are:

- `program3/ackermann.cc`

Recursive Linear Search
-----------------------
Any iterative algorithm can be written in a recursive manner as well. Implement linear search, but
recursively. Implement the following function:

- `int linearSearch(int array[], int size, int value)`: implements the linear search algorithm, but
  recursively. Returns the index where `value` was found or -1 if `value` was not found.

Note: it may help to have a second function where you do the actual recursion.

The files you will need for this exercise are:

- `program3/linear_search.cc`

Recursive Binary Search
-----------------------
The binary search algorithm presented in class is the iterative version. Implement binary search,
but recursively. Implement the following function:

- `int binarySearch(int array[], int size, int value)`: implements the binary search algorithm, but
  recursively. Returns the index where `value` was found or -1 if `value` was not found.

Note: it may help to have a second function where you do the actual recursion.

The files you will need for this exercise are:

- `program3/binary_search.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following command(s)
will be used to test and grade your code:

    $ bazel test program3:tests
