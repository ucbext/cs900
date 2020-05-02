#include <gtest/gtest.h>

#include "program4/person.h"
#include "program4/customer.h"
#include "program4/preferred_customer.h"

TEST(PersonTest, FirstName) {
  Person person;
  ASSERT_EQ("", person.get_first_name());
  person.set_first_name("Foo");
  ASSERT_EQ("Foo", person.get_first_name());
}

TEST(PersonTest, LastName) {
  Person person;
  ASSERT_EQ("", person.get_last_name());
  person.set_last_name("Foo");
  ASSERT_EQ("Foo", person.get_last_name());
}

TEST(PersonTest, Address) {
  Person person;
  ASSERT_EQ("", person.get_address());
  person.set_address("Foo");
  ASSERT_EQ("Foo", person.get_address());
}

TEST(PersonTest, City) {
  Person person;
  ASSERT_EQ("", person.get_city());
  person.set_city("Foo");
  ASSERT_EQ("Foo", person.get_city());
}

TEST(PersonTest, State) {
  Person person;
  ASSERT_EQ("", person.get_state());
  person.set_state("Foo");
  ASSERT_EQ("Foo", person.get_state());
}

TEST(PersonTest, Zip) {
  Person person;
  ASSERT_EQ(0, person.get_zip());
  person.set_zip(1);
  ASSERT_EQ(1, person.get_zip());
}

TEST(PersonTest, NegativeZip) {
  Person person;
  person.set_zip(1);
  ASSERT_EQ(1, person.get_zip());

  person.set_zip(-1);
  ASSERT_EQ(1, person.get_zip());
}

TEST(PersonTest, Phone) {
  Person person;
  ASSERT_EQ(0, person.get_phone());
  person.set_phone(1);
  ASSERT_EQ(1, person.get_phone());
}

TEST(PersonTest, NegativePhone) {
  Person person;
  person.set_phone(1);
  ASSERT_EQ(1, person.get_phone());

  person.set_phone(-1);
  ASSERT_EQ(1, person.get_phone());
}

TEST(CustomerTest, InheritsFromPerson) {
  Customer* customer = new Customer;
  Person* person = dynamic_cast<Person*>(customer);
  ASSERT_NE(nullptr, person);
}

TEST(CustomerTest, CustomerNumber) {
  Customer customer;
  ASSERT_EQ(0, customer.get_customer_number());
  customer.set_customer_number(1);
  ASSERT_EQ(1, customer.get_customer_number());
}

TEST(CustomerTest, NegativeCustomerNumber) {
  Customer customer;
  customer.set_customer_number(1);
  ASSERT_EQ(1, customer.get_customer_number());

  customer.set_customer_number(-1);
  ASSERT_EQ(1, customer.get_customer_number());
}

TEST(CustomerTest, MailingList) {
  Customer customer;
  ASSERT_EQ(false, customer.get_mailing_list());
  customer.set_mailing_list(true);
  ASSERT_EQ(true, customer.get_mailing_list());
}

TEST(PreferredCustomerTest, InheritsFromCustomer) {
  PreferredCustomer* preferred_customer = new PreferredCustomer;
  Customer* customer = dynamic_cast<Customer*>(preferred_customer);
  ASSERT_NE(nullptr, customer);
}

TEST(PreferredCustomerTest, PurchaseAmount) {
  PreferredCustomer customer;
  ASSERT_EQ(0, customer.get_purchase_amount());
  customer.set_purchase_amount(1);
  ASSERT_EQ(1, customer.get_purchase_amount());
}

TEST(PreferredCustomerTest, NegativePurchaseAmount) {
  PreferredCustomer customer;
  customer.set_purchase_amount(1);
  ASSERT_EQ(1, customer.get_purchase_amount());

  customer.set_purchase_amount(-1);
  ASSERT_EQ(1, customer.get_purchase_amount());
}

TEST(PreferredCustomerTest, DiscountLevel) {
  PreferredCustomer customer;

  customer.set_purchase_amount(499.99);
  ASSERT_EQ(0, customer.get_discount_level());

  customer.set_purchase_amount(500);
  ASSERT_EQ(5, customer.get_discount_level());

  customer.set_purchase_amount(999.99);
  ASSERT_EQ(5, customer.get_discount_level());

  customer.set_purchase_amount(1000);
  ASSERT_EQ(6, customer.get_discount_level());

  customer.set_purchase_amount(1499.99);
  ASSERT_EQ(6, customer.get_discount_level());

  customer.set_purchase_amount(1500);
  ASSERT_EQ(7, customer.get_discount_level());

  customer.set_purchase_amount(1999.99);
  ASSERT_EQ(7, customer.get_discount_level());

  customer.set_purchase_amount(2000);
  ASSERT_EQ(10, customer.get_discount_level());
}