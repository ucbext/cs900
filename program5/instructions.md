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

Dynamic Array
-------------
Vectors in C++ are like dynamic arrays which can grow and shrink as necessary. Someone had to write
the code for them in order to be included into the C++ standard library. For the purposes of this
exercise, let's assume that you are that person. Write a templatized class, `DynamicArray`, which
behaves like a vector but with slight modifications. Remember that in a standard vector, as elements
are added, the vector grows (doubles) to allow for new elements being added. In our `DynamicArray`
we also want to grow, but instead of doubling, we will triple in size to allow for the new elements
being added. Implement the class along with the following functions within your class.

- `Constructor`: provide a default constructor and a constructor that accepts an initial size of the
  dynamic array. The default constructor should initialize the `DynamicArray` to zero elements.
- `Destructor`: free the memory held by the `DynamicArray`
- `int at(int index)`: access a specific integer at the given index
- `int first()`: access the first element
- `int last()`: access the last element
- `bool empty()`: return `true` if the `DyanmicArray` is empty, `false` otherwise
- `int size()`: return the number of elements currently in the `DynamicArray`
- `int capacity()`: return the total amount of elements the `DynamicArray` can hold before it will
  have to grow larger
- `void shrink()`: remove excess capacity and shrink the `DynamicArray` capacity to exactly the
  number of elements currently being used in the `DynamicArray`
- `void clear()`: clear the contents of the `DynamicArray`
- `void push_back(int value)`: add an element to the `DynamicArray`, resizing if necessary
- `void pop_back()`: remove the last element from the `DynamicArray`

You may not use vectors from the standard library for this exercise.

The files you will need for this exercise are:

- `program4/dynamic_array.h`
- `program4/dynamic_array.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following command(s)
will be used to test and grade your code:

    $ bazel test program5:tests
