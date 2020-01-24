Program 2
---------
Program 2 covers concepts found in the following chapters:

- Chapter 5: Looping
- Chapter 6: Functions
- Chapter 7: Arrays

To get you started, each program file along with the appropriate Bazel configuration has already
been setup for you in the `program2` directory. You simply need to fill out each file with the
appropriate code.

In order for tests to pass and ensure that you get the proper grade that you deserve, you must
ensure that your output case-sensitively matches the output that the tests expect.

Least Greatest
--------------
Write a program with a loop that lets the user enter a series of integers. The user should enter -99
to signal the end of the series. After all the numbers have been entered, the program should display
the largest and smallest numbers entered.

The files you will need for this exercise are:

- `program2/least_greatest.cc`

Random Number Guessing
----------------------
Write a program that generates a random number between 0 and 1,000 and asks the user to guess what
the number is. If the user's guess is higher than the random number, the program should display
"Too high, try again." If the user's guess is lower than the random number, the program should
display "Too low, try again." The program should use a loop that repeats until the user correctly
guesses the random number. Keep track of how many guesses the user makes. When the user correctly
guesses the random number, the program should display the number of guesses.

The files you will need for this exercise are:

- `program2/random_number_guessing.cc`

Lowest Score
------------
Write a program that calculates the average of a group of test scores, where the lowest score in the
group is dropped. It should use the following functions:

- `void get_score`: should ask the user for a test score, store it in a reference
    parameter variable, and validate it as being between 0 and 100. This function should be called
    by `main` once for each of the five scores to be entered.
- `float find_lowest`: should find and return the lowest of the five scores passed to
    it. It should be called by `calc_average`, which uses the function to determine which of the
    five scores to drop.
- `float calc_average`: should calculate and return the average of the four highest
    scores. This function should be called just once by `main` and should be passed the five scores.

The files you will need for this exercise are:

- `program2/lowest_score.cc`

Is Prime
--------
A prime number is a number that is only evenly divisible by itself and 1. For example, the number 5
is prime because it can only be evenly divided by 1 and 5. The number 6, however, is not prime
because it can be divided evenly by 1, 2, 3, and 6.

Write a function name `bool is_prime`, which takes an integer as an argument and returns
`true` if the argument is a prime number, or `false` otherwise. Demonstrate the function in a
complete program.

Hint: Recall that the `%` operator divides one number by another and returns the remainder
of the division. In an expression such as `num1 % num2`, the `%` operator will return 0 if `num1` is
evenly divisible by `num2`.

The files you will need for this exercise are:

- `program2/is_prime.cc`

Payroll
-------
Write a program that uses the following arrays:

- `emp_id`: an array of seven long integers to hold employee identification numbers.
    The array should be initialized with the following numbers:
    - 5658845
    - 4520125
    - 7895122
    - 8777541
    - 8451277
    - 1302850
    - 7580489
- `hours`: an array of seven integers to hold the number of hours worked by each
    employee
- `pay_rate`: an array of seven doubles to hold each employee's hourly pay rate
- `wages`: an array of seven doubles to hold each employee's gross wages

The program should relate the data in each array through the subscripts. For example, the number in
element 0 of the hours array should be the number of hours worked by the employee whose
identification number is stored in element 0 of the `emp_id` array. That same employee's pay rate
should be stored in element 0 of the `pay\_rate` array.

The program should display each employee number and ask the user to enter that employee's hours and
pay rate. It should then calculate the gross wages for that employee (hours times pay rate) and
store them in the `wages` array. After the data has been entered for all the employees, the
program should display each employee's identification number and gross wages.

Do not accept negative values for hours or numbers less than 15.00 for pay rate.

The files you will need for this exercise are:

- `program2/payroll.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following commands will
be used to test and grade your code:

    $ bazel test program2:tests
