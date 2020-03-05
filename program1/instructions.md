Program 1
---------
Program 1 covers concepts found in the following chapters:

- Chapter 1: Thinking Like a Programmer
- Chapter 2: Basic Language Syntax
- Chapter 3: Expressions and Interactivity
- Chapter 4: Making decisions

Before you begin, you may want to go back and review these chapters to ensure you understand them
fully. To get you started, each program file along with the appropriate Bazel configuration has
already been setup for you in the `program1` directory. You simply need to fill out each file with
the appropriate code.

In order for tests to pass and ensure that you get the proper grade that you deserve, you must
ensure that your output case-sensitively matches the output that the tests expect.

Stock Commission
----------------
Kathryn bought 750 shares of stock at a price of $35.00 per share. She must pay her stockbroker a 2%
commission for the transaction. Write a program that calculates and displays the following:

- The amount paid for the stock alone (without the commission)
- The amount of the commission
- The total amount paid (for the stock plus the commission)

The files you will need for this exercise are:

- `program1/stock_commission.cc`

Angle Calculator
----------------
Write a program that asks the user for an angle, entered in radians. The program should then display
the sine, cosine, and tangent of the angle. (Use the `sin`, `cos`, and `tan` library functions to
determine these values.)

The files you will need for this exercise are:

- `program1/angle_calculator.cc`

Monthly Payments
----------------
The monthly payment on a loan may be calculated by the following formula:

    Principal = L * (r(1 + r)^n) / ((1 + r)^n - 1)

Where `r` is the monthly interest rate, which is the annual interest rate divided by 12 (12\% annual
interest would be 1 percent monthly interest). `n` is the number of payments, and `L` is the amount
of the loan. Write a program that asks for these values and displays a report like so:

    Loan Amount: $10000.00
    Monthly Interest Rate: 1.00%
    Number of Payments: 36
    Monthly Payment: $332.14
    Amount Paid Back: $11957.15
    Interest Paid: $1957.15

When displaying your output, ensure that the spacing and alignment is exactly as shown above.

The files you will need for this exercise are:

- `program1/monthly_payments.cc`

Freezing and Boiling Points
---------------------------
The following table lists the freezing and boiling points of several substances.

| Substance     | Freezing Point (F) | Boiling Point (F) |
| ------------- | ------------------ | ----------------- |
| Ethyl Alcohol | -173               | 172               |
| Mercury       | -38                | 676               |
| Oxygen        | -362               | -306              |
| Water         | 32                 | 212               |

Write a program that asks the user to enter a temperature and then shows all the substances that
will freeze at that temperature and all that will boil at that temperature. For example, if the user
enters -20 the program should report that water will freeze and oxygen will boil at that
temperature.

The files you will need for this exercise are:

- `program1/freezing_boiling_points.cc`

Mobile Service Provider
-----------------------
A mobile phone service provider has three different subscription packages for its customers:

| Package Name  | Minutes   | Base Cost (per month) | Additional Minutes (per minute) |
| ------------- | --------- | --------------------- | ------------------------------- |
| Package A     | 450       | $39.99                | $0.45                           |
| Package B     | 900       | $59.99                | $0.40                           |
| Package C     | Unlimited | $69.99                | $0.00                           |

Write a program that calculates a customer's monthly bill. It should ask which package the customer
has purchased and how many minutes were used. It should then display the total amount due. If the
user enters a package other than A, B, or C, display an error message and exit the program. Finally,
display how much money Package A customers would save if they purchased packages B or C, and how
much money Package B customers would save if they purchased Package C. If there would be no savings,
no message should be printed.

The files you will need for this exercise are:

- `program1/mobile_service_provider.cc`

Testing your code
-----------------
Tests have already been written to help you ensure that your code works. The following commands will
be used to test and grade your code:

    $ bazel test program1:tests
