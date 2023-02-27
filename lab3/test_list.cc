// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "linked_list.h"
#include "catch.hpp"

#include <random>
#include <iostream>
#include <string>

using namespace std;

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE("Create an empty list")
{
  Linked_list l{};

  REQUIRE(l.is_empty() == true);
  REQUIRE(l.size() == 0);
}

Linked_list get_list()
{
  Linked_list l{};
  l.insert(1);
  l.insert(3);
  l.insert(2);
  return l;
}

bool sorted_list(Linked_list const &l)
{
  if (!l.is_empty())
  {
    for (int i{0}; i < l.size() - 1; ++i)
    {
      if (l.get_index(i) > l.get_index(i + 1))
      {
        return false;
      }
    }
    return true;
  }
  return false;
  return false;
}

TEST_CASE("Testing insert and size")
{
  Linked_list l{};
  l.insert(1);

  CHECK(l.size() == 1);
  l.insert(2);
  CHECK(l.size() == 2);
  l.insert(3);
  CHECK(l.size() == 3);
  l.insert(8);
  l.insert(4);
  l.insert(6);
  l.insert(5);
  l.insert(12);
  l.insert(10);

  // Inserting a value that already exists
  l.insert(10);

  l.insert(0);
  l.insert(-2);

  CHECK(l.size() == 12);

  CHECK(sorted_list(l));
}

TEST_CASE("Testing remove and size")
{
  Linked_list l{};

  REQUIRE(l.is_empty());

  l.insert(1);
  l.insert(2);
  l.insert(4);
  l.insert(3);

  CHECK(l.size() == 4);

  l.remove(3);

  // Checking that size is decreased
  CHECK(l.size() == 3);

  // Checking that the list is sorted after a remove
  CHECK(sorted_list(l));

  Linked_list l2{};

  REQUIRE(l2.is_empty());

  l2.remove(1);

  CHECK(l2.is_empty());

  // Checking that a remove is not possible when the list is empty
  CHECK(l2.size() == 0);
}

TEST_CASE("Testing empty list")
{
  Linked_list l{};
  REQUIRE(l.is_empty());

  l.insert(2);
  l.insert(4);
  l.insert(1);
  l.insert(3);

  CHECK(!l.is_empty());

  l.empty_list();

  CHECK(l.is_empty());
}

TEST_CASE("Testing get_index")
{
  Linked_list l{};

  l.insert(2);
  l.insert(4);
  l.insert(1);
  l.insert(3);

  CHECK(l.get_index(2) == 3);
  CHECK(l.get_index(0) == 1);

  // Index out of bounds returns 0 and prints index larger than size of list
  // NOTE: This does print an error message to the terminal, mostly directed towards the user who would try and access an index out of range. Should not be seen as a debug print for the testing
  CHECK(l.get_index(5) != 2);
  CHECK(l.get_index(100) == 0);
}

TEST_CASE("Testing print")
{
  Linked_list l{};

  l.insert(2);
  l.insert(4);
  l.insert(1);
  l.insert(3);

  CHECK(sorted_list(l));

  string expected_l_print = "List: 1 -> 2 -> 3 -> 4";

  CHECK(expected_l_print == l.to_string());

  Linked_list l2{};
  l2.insert(8);
  l2.insert(4);
  l2.insert(6);
  l2.insert(5);
  l2.insert(12);
  l2.insert(10);
  l2.insert(0);
  l2.insert(-2);

  CHECK(sorted_list(l2));

  string expected_l2_print = "List: -2 -> 0 -> 4 -> 5 -> 6 -> 8 -> 10 -> 12";

  CHECK(expected_l2_print == l2.to_string());
}

TEST_CASE("Testing copy constructor")
{
  Linked_list l{};

  l.insert(2);
  l.insert(4);
  l.insert(1);
  l.insert(3);

  Linked_list l2{l};

  REQUIRE(!l2.is_empty());

  // Checking that they are the same lists
  CHECK(l == l2);

  // Inserting to l2 should not affect l, and only change l2. They should not be the same list after an insert, therefore a deep copy of l and not a shallow
  l2.insert(2);
  CHECK_FALSE(l == l2);

  // Emptying l should not empty l2
  l.empty_list();
  CHECK(!l2.is_empty());
}

TEST_CASE("Testing copy operator")
{
  Linked_list l{};

  l.insert(2);
  l.insert(4);
  l.insert(1);
  l.insert(3);

  Linked_list l2{};
  l2.insert(8);
  l2.insert(4);
  l2.insert(6);
  l2.insert(5);
  l2.insert(12);
  l2.insert(10);
  l2.insert(0);
  l2.insert(-2);

  // Should not equal
  CHECK_FALSE(l == l2);

  // Copy operator that creates a deep copy of l and deletes existing content of l2
  l2 = l;

  // Should be same after copy operator
  CHECK(l == l2);

  // Asserting that they have the same size
  CHECK(l.size() == l2.size());

  // Changing l2 should not affect l, meaning that it is a deep copy
  l2.remove(2);
  CHECK_FALSE(l == l2);
}

TEST_CASE("Testing move constructor")
{
  // Instatiating move_list with the
  Linked_list move_list{get_list()};
  Linked_list l{std::move(move_list)};

  // Checks that the pointer from the function is asserted to nullptr, so the destructor isn't called when the temporary object is out of scope
  REQUIRE(!l.is_empty());

  CHECK(sorted_list(l));

  CHECK(move_list.is_empty());
}

TEST_CASE("Testing move operator")
{
  Linked_list l{};
  l.insert(1);
  l.insert(3);
  l.insert(5);

  Linked_list l2{};
  l2.insert(4);
  l2.insert(6);
  l2.insert(8);

  // Assigning l to the function l2 with std::move, which makes l a shallow copy of l2
  l = std::move(l2);

  // Checks that the pointer from the function is asserted to nullptr, so the destructor isn't called when the temporary object is out of scope
  REQUIRE(!l.is_empty());

  CHECK(sorted_list(l));

  CHECK(l2.is_empty());
}
