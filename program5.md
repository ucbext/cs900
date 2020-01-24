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
ensure that your output case-sensitively matches the output that the tests expect.

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

Person Customer Data
--------------------
Design a class named `PersonData` with the following member variables:

- `last_name`
- `first_name`
- `address`
- `city`
- `state`
- `zip`
- `phone`

Write the appropriate accessor and mutator functions for these member variables. Next, design a
class named `CustomerData`, which is derived from the `PersonData` class. The `CustomerData` class
should have the following member variables:

- `customer_number`
- `mailing_list`

The `customer_number` variable will be used to hold a unique integer for each customer. The
`mailing_list` variable should be a `bool`. It will be set to `true` if the customer wishes to be on
a mailing list, or `false` if the customer does not wish to be on a mailing list. Write appropriate
accessor and mutator functions for these member variables. Demonstrate an object of the
`CustomerData` class in a simple program.

The files you will need for this exercise are:

- `program5/person_customer_data.h`
- `program5/person_customer_data.cc`

Preferred Customer
------------------
A retail store has a preferred customer plan where customers may earn discounts on all their
purchases. The amount of a customer’s discount is determined by the amount of the customer’s
cumulative purchases in the store.

- When a preferred customer spends $500, he or she gets a 5% discount on all future purchases
- When a preferred customer spends $1,000, he or she gets a 6% discount on all future purchases
- When a preferred customer spends $1,500, he or she gets a 7% discount on all future purchases
- When a preferred customer spends $2,000 or more, he or she gets a 10% discount on all future
    purchases

Design a class named `PreferredCustomer`, which is derived from the `CustomerData`
class you created earlier. The `PreferredCustomer` class should have the following member
variables:

- `purchase_amount` (a double)
- `discount_level` (a double)

The `purchase_amount` variable holds the total of a customer's purchases to date. The
`discount_level` variable should be set to the correct discount percentage, according to the
store's preferred customer plan. Write appropriate member functions for this class and demonstrate
it in a simple program.

The files you will need for this exercise are:

- `program5/preferred_customer.h`
- `program5/preferred_customer.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following commands will
be used to test and grade your code:

    $ bazel test program5:tests
