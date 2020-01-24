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

String Reverse
--------------
Write a recursive function that accepts a string object as its argument and prints the string in
reverse order. Demonstrate the function in a driver program.

The files you will need for this exercise are:

- `program4/string_reverse.cc`

Word Separator
--------------
Write a program that accepts as input a sentence in which all
of the words are run together, but the first character of each word is uppercase. Convert the
sentence to a string in which the words are separated by spaces and only the first word starts with
an uppercase letter. For example the string "StopAndSmellTheRoses." would be converted to "Stop
and smell the roses."

The files you will need for this exercise are:

- `program4/word_separator.cc`

Password Verification
---------------------
Imagine you are developing a software package that requires users to enter their own passwords. Your
software requires that users' passwords meet the following criteria:

- The password should be at least six characters long
- The password should contain at least one uppercase letter
- The password should contain at least one lowercase letter
- The password should have at least one digit

Write a program that asks for a password and then verifies that it meets the stated criteria. If it
doesn't, the program should display a message telling the user why.

Hint: write each check in its own function for a more modular and easy to reason about program.

The files you will need for this exercise are:

- `program4/password_verification.cc`

Movie Data
----------
Write a program that uses a class named `MovieData` to store the following information about a
movie:

- Title
- Director
- Year Released
- Running Time (in minutes)
- Production cost
- Gross revenue

The program should create two `MovieData` variables, store values in their members using setter
methods, and pass each `MovieData` variable, in turn, to a function that displays the information
about the movie in a clearly formatted manner. The function should also display the movie's gross
profit or loss.

The files you will need for this exercise are:

- `program4/movie_data.h`
- `program4/movie_data.cc`

Car Class
---------
Write a class named `Car` that has the following member variables:

- `year`: an `int` that holds the car's year
- `make`: a `string` that holds the make of the car
- `speed`: an `int` that holds the car's current speed

In addition, the class should have the following constructor and other member functions.

- `Constructor`: The constructor should accept the car’s year and make as arguments. These values
    should be assigned to the object's `year` and `make` member variables. The constructor should
    also assign 0 to the `speed` member variable.
- `Accessor`: Appropriate accessor functions to get the values stored in an object’s `year`, `make`,
    and `speed` member variables.
- `accelerate`: The `accelerate` function should add 5 to the `speed` member variable each time it
    is called.
- `brake`: The `brake` function should subtract 5 from the `speed` member variable each time it is
    called.

Demonstrate the class in a program that creates a `Car` object, and then calls the `accelerate`
function five times. After each call to the `accelerate` function, get the current `speed` of the
car and display it. Then, call the `brake` function five times. After each call to the `brake`
function, get the current `speed` of the car and display it.

The files you will need for this exercise are:

- `program4/car.h`
- `program4/car.cc`

Inventory
---------
Write a program that simulates inventory bins in a warehouse. Each bin holds a number of the same
type of parts. The program should use a class that keeps the following data:

- Description of the part kept in the bin
- Number of parts in the bin

The program should have an array of 10 bins, initialized with the following data:

| Part Description | Number of Parts in the Bin |
| ---------------- | -------------------------- |
| Valve            | 10                         |
| Bearing          | 5                          |
| Bushing          | 15                         |
| Coupling         | 21                         |
| Flange           | 7                          |
| Gear             | 5                          |
| Gear Housing     | 5                          |
| Vacuum Gripper   | 25                         |
| Cable            | 18                         |
| Rod              | 12                         |

The program should have the following functions:

- `addParts`: increases a specific bin's part count by a specified number
- `removeParts`: decreases a specific bin's part count by a specified number

When the program runs, it should repeat a loop that performs the following steps: The user should
see a list of what each bin holds and how many parts are in each bin. The user is then presented
with a menu allowing them to choose from the following options:

- Add parts to a bin
- Remove parts from a bin
- Quit the program

If the user wants to add or remove parts from a bin, the user is prompted with how many parts to add
or remove and the operation is performed. The loop then repeats, showing the updated bin data on the
screen. No bin can hold more than 30 parts, so don't let the user add more than a bin can hold.
Also, don't accept negative values for the number of parts being added or removed.

The files you will need for this exercise are:

- `program4/inventory.h`
- `program4/inventory.cc`

Extra Credit: Array
-------------------
Design a class that has an array of floating-point numbers. The constructor should accept an integer
argument and dynamically allocate the array to hold that many numbers. The destructor should free
the memory held by the array. In addition, there should be member functions to perform the following
operations:


- Store a number in any element of the array
- Retrieve a number from any element of the array
- Return the highest value stored in the array
- Return the lowest value stored in the array
- Return the sum of all the values stored in the array
- Return the average of all the numbers stored in the array

Your program should reuse as much of the above functions as possible. Demonstrate the class in a
program.

The files you will need for this exercise are:

- `program4/array.h`
- `program4/array.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following commands will
be used to test and grade your code:

    $ bazel test program4:tests
