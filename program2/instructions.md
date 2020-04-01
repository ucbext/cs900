Program 2
---------
Program 2 covers concepts found in the following chapters:

- Chapter 5: Looping
- Chapter 6: Functions
- Chapter 7: Arrays

Before you begin, you may want to go back and review these chapters to ensure you understand them
fully. To get you started, each program file along with the appropriate Bazel configuration has
already been setup for you in the `program2` directory. You simply need to fill out each file with
the appropriate code.

In order for tests to pass and ensure that you get the proper grade that you deserve, you must
ensure that your output case-sensitively matches the output that the tests expect. Use the example
outputs found at the end of every section to help guide how you format your output.

Least Greatest
--------------
Write a program with a loop that lets the user enter a series of integers. The user should enter -99
to signal the end of the series. After all the numbers have been entered, the program should display
the largest and smallest numbers entered.

The files you will need for this exercise are:

- `program2/least_greatest.cc`

Example output:

    Enter an integer: 77
    Enter an integer: 23
    Enter an integer: 48
    Enter an integer: 19
    Enter an integer: 34
    Enter an integer: -99
    The largest number was 77
    The smallest number was 19

Random Number Guessing
----------------------
Write a program that generates a random number between 0 and 1,000 and asks the user to guess what
the number is. If the user's guess is higher than the random number, the program should display
"<number> is too high, try again." If the user's guess is lower than the random number, the program
should display "<number> is too low, try again." The program should use a loop that repeats until
the user correctly guesses the random number. Keep track of how many guesses the user makes. When
the user correctly guesses the random number, the program should display the number of guesses.

The files you will need for this exercise are:

- `program2/random_number_guessing.cc`

Example output:

    Make a guess: 500
    500 is too low, try again.
    Make a guess: 750
    750 is too high, try again.
    Make a guess: 625
    625 is too high, try again.
    Make a guess: 562
    562 is too high, try again.
    Make a guess: 531
    531 is too high, try again.
    Make a guess: 515
    515 is too high, try again.
    Make a guess: 507
    507 is too low, try again.
    Make a guess: 511
    511 is too low, try again.
    Make a guess: 513
    You got the correct answer in 9 attempts!

Lowest Score
------------
Write functions that calculate the average of a group of test scores, where the lowest score in the
group is dropped. It should use the following functions:

- `void getScore`: should ask the user for a test score and validate it as being between 0 and
  100. If the user enters a valid score, store it in the reference parameter variable. If the user
   enters an invalid score, don't change the reference parameter variable. Finally, ask the user
   only once. Don't keep asking until the user enters a valid score.
- `float findLowest`: should take an array and its size and return the lowest of the scores passed
  to it. It should be called by `calcAverage`, which uses the function to determine which of the
  five scores to drop.
- `float calcAverage`: should take an array and its size and return the average of the scores
  passed to it, making sure to drop the lowest one.

The files you will need for this exercise are:

- `program2/lowest_score.cc`

Is Prime
--------
A prime number is a number that is only evenly divisible by itself and 1. For example, the number 5
is prime because it can only be evenly divided by 1 and 5. The number 6, however, is not prime
because it can be divided evenly by 1, 2, 3, and 6.

Write a function name `bool isPrime`, which takes an integer as an argument and returns `true` if
the argument is a prime number, or `false` otherwise. Demonstrate the function in a complete
program.

Hint: Recall that the `%` operator divides one number by another and returns the remainder of the
division. In an expression such as `num1 % num2`, the `%` operator will return 0 if `num1` is evenly
divisible by `num2`.

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
should be stored in element 0 of the `pay_rate` array.

The program should display each employee number and ask the user to enter that employee's hours and
pay rate. It should then calculate the gross wages for that employee (hours times pay rate) and
store them in the `wages` array. After the data has been entered for all the employees, the
program should display each employee's identification number and gross wages.

Do not accept negative values for hours or numbers less than 15.00 for pay rate.

The files you will need for this exercise are:

- `program2/payroll.cc`

Example output:

    Enter the hours for employee 5658845: 10
    Enter the pay rate for employee 5658845: $16
    Enter the hours for employee 4520125: 15
    Enter the pay rate for employee 4520125: $17
    Enter the hours for employee 7895122: 20
    Enter the pay rate for employee 7895122: $18
    Enter the hours for employee 8777541: 25
    Enter the pay rate for employee 8777541: $19
    Enter the hours for employee 8451277: 30
    Enter the pay rate for employee 8451277: $20
    Enter the hours for employee 1302850: 35
    Enter the pay rate for employee 1302850: $21
    Enter the hours for employee 7580489: 40
    Enter the pay rate for employee 7580489: $22
    Employee 5658845: $160
    Employee 4520125: $255
    Employee 7895122: $360
    Employee 8777541: $475
    Employee 8451277: $600
    Employee 1302850: $735
    Employee 7580489: $880

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following command(s)
will be used to test and grade your code:

    $ program2/test.sh
