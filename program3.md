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

Lottery
-------
A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit "lucky"
combinations. Write a program that initializes an array or a vector with these numbers and then
generates a random 5-digit number signifying this week's winning number. The program should then
perform a linear search through the list of the player's numbers and report whether or not one of
the tickets is a winner this week. Here are the numbers:

- 13579
- 26791
- 26792
- 33445
- 55555
- 62483
- 77777
- 79422
- 85647
- 93121

The files you will need for this exercise are:

- `program3/lottery.cc`

Ackermann
---------
Ackermann's Function is a recursive mathematical algorithm that can be used to test how well a
computer performs recursion. Write a function `A(m, n)` that solves Ackermann's Function. Use the
following logic in your function:

    If m = 0 then return n + 1
    If n = 0 then return A(m - 1, 1)
    Otherwise, return A(m - 1, A(m, n - 1))

Test your function in a driver program that displays the following values: `A(0, 0) A(0, 1) A(1, 1)
A(1, 2) A(1, 3) A(2, 2) A(3, 2)`.

The files you will need for this exercise are:

- `program3/ackermann.cc`

Reverse
-------
Write a function that accepts an integer array and the array's size as arguments. The function
should create a copy of the array, except that the element values should be reversed in the copy.
The function should return a pointer to the new array. Demonstrate the function in a complete
program.

The files you will need for this exercise are:

- `program3/reverse.cc`

Search Benchmark
----------------
Write a program that benchmarks (compares the speed) of linear search versus binary search. To do
so, you'll need to write the following functions:

- `int linearSearch(int array[], int size, int value)`: implements the linear search algorithm.
    Returns the index where `value` was found or -1 if `value` was not found.
- `int binarySearch(int array[], int size, int value)`: implements the binary search algorithm.
    Returns the index where `value` was found or -1 if `value` was not found.
- `int* generateData(int size)`: allocates an array of length `size` integers, fills each element
    with the element's index, and returns it. The resulting array should have ascending values
    starting from `0` up to `size - 1` (e.g. `0, 1, 2, 3, 4, ...`).
- `int getTime()`: returns the current time in microseconds since January 1, 1970.

Finally, in your `main` function, use the `generateData` function you defined to create an array of
1,000,000 integers. Search for a random number in the array using `linearSearch` and `binarySearch`.
Time their executions by calling `getTime` before and after the call to each search function (the
difference of the two times is the time taken). Note: remember to call `srand(time(nullptr))` at the
start of your `main` function.

After you are done, adjust the size of the array and see how the performance of each algorithm
changes.

The files you will need for this exercise are:

- `program3/search_benchmark.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following commands will
be used to test and grade your code:

    $ bazel test program3:tests
