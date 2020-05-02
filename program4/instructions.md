Program 4
---------
Program 4 covers concepts found in the following chapters:

- Chapter 10: Strings and the String Class
- Chapter 13: Classes
- Chapter 15: Inheritance and Polymorphism

Before you begin, you may want to go back and review these chapters to ensure you understand them
fully. To get you started, each program file along with the appropriate Bazel configuration has
already been setup for you in the `program4` directory. You simply need to fill out each file with
the appropriate code.

In order for tests to pass and ensure that you get the proper grade that you deserve, you must
ensure that your output case-sensitively matches the output that the tests expect.

Word Separator
--------------
Write a function, `separate_words`, that accepts as input a sentence in which all of the words are
run together, but the first character of each word is uppercase. Convert the sentence to a string in
which the words are separated by spaces and only the first word starts with an uppercase letter. For
example the string "StopAndSmellTheRoses." would be converted to "Stop and smell the roses."

The files you will need for this exercise are:

- `program4/word_separator.h`
- `program4/word_separator.cc`

Password Verification
---------------------
Imagine you are developing a software package that requires users to enter their own passwords. Your
software requires that users' passwords meet the following criteria:

- The password should be at least six characters long
- The password should contain at least one uppercase letter
- The password should contain at least one lowercase letter
- The password should have at least one digit

The function `verify_password` has already been written for you. However, it doesn't quite work yet.
In order to get it to work, you need to write the following functions. The functions should return
`true` if the password is valid for that specific check and `false` otherwise. Writing each check in
its own function allows for a more modular and easy to reason about program.

- `bool has_six_chars(const std::string& password)`
- `bool has_uppercase(const std::string& password)`
- `bool has_lowercase(const std::string& password)`
- `bool has_digit(const std::string& password)`

The files you will need for this exercise are:

- `program4/password_verification.h`
- `program4/password_verification.cc`

Retail Store
------------
A retail store has hired you to implement their data model by writing classes that will store their
customer's information. Write a class, `Person`, with the following member variables:

- `string first_name`
- `string last_name`
- `string address`
- `string city`
- `string state`
- `int zip`
- `int phone`

Write the appropriate getter and setter functions for these member variables. Next, write a class,
`Customer`, which is derived from `Person`. The `Customer` class should have the following
additional member variables:

- `int customer_number`: holds a unique integer for each customer
- `bool mailing_list`: set to `true` if the customer wishes to be on the mailing list, `false`
  otherwise

Again, write the appropriate getter and setter methods for these member variables. Finally, this
retail store has a preferred customer plan where customers may earn discounts on all their
purchases. The amount of a customer's discount is determined by the amount of the customer's
cumulative purchases in the store.

- When a preferred customer spends $500, he or she gets a 5% discount on all future purchases
- When a preferred customer spends $1,000, he or she gets a 6% discount on all future purchases
- When a preferred customer spends $1,500, he or she gets a 7% discount on all future purchases
- When a preferred customer spends $2,000 or more, he or she gets a 10% discount on all future
  purchases

Write a class, `PreferredCustomer`, which is derived from the `Customer` class you created earlier.
The `PreferredCustomer` class should have the following member variables:

- `float purchase_amount`: holds the total of a customer's purchases to date
- `float discount_level`: the discount percentage this customer receives, according to the store's
  preferred customer plan above

Again, write appropriate getter and setter methods for these member variables.

The files you will need for this exercise are:

- `program4/person.h`
- `program4/person.cc`
- `program4/customer.h`
- `program4/customer.cc`
- `program4/preferred_customer.h`
- `program4/preferred_customer.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following command(s)
will be used to test and grade your code:

    $ bazel test program4:tests
