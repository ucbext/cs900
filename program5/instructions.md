Program 5
---------
Program 5 covers concepts found in the following chapters:

- Chapter 16: Exceptions, Templates, and the STL (Standard Template Library)
- Chapter 17: Linked Lists
- Chapter 18: Stacks and Queues

Before you begin, you may want to go back and review these chapters to ensure you understand them
fully. To get you started, each program file along with the appropriate Bazel configuration has
already been setup for you in the `program5` directory. You simply need to fill out each file with
the appropriate code.

In order for tests to pass and ensure that you get the proper grade that you deserve, you must
ensure that your output case-sensitively matches the output that the tests expect. Use the example
outputs found at the end of every section to help guide how you format your output.

Test Scores
-----------
Write a class named `TestScores`. The class' constructor should accept an array of test scores as
its argument, along with the array's size. The class should have a member function that returns the
average of the test scores. If any test score in the array is negative or greater than 100, the
class should throw an exception. Demonstrate the class in a program.

The files you will need for this exercise are:

- `program5/test_scores.h`
- `program5/test_scores.cc`

Templatized Sum
---------------
Write a templatized function `sum`. The function should accept a templatized array and the size of
the array. The function should calculate the sum of all of the values in the array. Write a simple
program that demonstrates the template function with various data types.

The files you will need for this exercise are:

- `program5/sum.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following command(s)
will be used to test and grade your code:

    $ bazel test program5:tests
