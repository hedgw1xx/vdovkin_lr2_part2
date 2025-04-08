#include "CUTE/cute/cute.h"
#include "CUTE/cute/cute_runner.h"
#include "CUTE/cute/cute_suite.h"
#include "CUTE/cute/cute_test.h"
#include "CUTE/cute/ide_listener.h"
#include "vdovkin_mathTask.hpp"

using namespace cute;

void testUserInput_Empty() {
  string str = "";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter() {
  string str = "a";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testUserInput_NegativeValue() {
  string str = "-1";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testUserInput_DigitLetterValue() {
  string str = "1a";
  bool expected = false;
  bool actual = UserInput(str);
  ASSERT_EQUAL(expected, actual);
}

void testCalcRemainder() {
  int a = 5, b = 6, c = 3;
  int expected = 2;
  int actual = CalcRemainder(a, b, c);
  ASSERT_EQUAL(expected, actual);
}

void testCalcIntegerPart() {
  int a = 5, b = 6, c = 3;
  int expected = 3;
  int actual = CalcIntegerPart(a, b, c);
  ASSERT_EQUAL(expected, actual);
}

int main() {
  suite s;

  s.push_back(CUTE(testUserInput_Empty));
  s.push_back(CUTE(testUserInput_Letter));
  s.push_back(CUTE(testUserInput_NegativeValue));
  s.push_back(CUTE(testUserInput_DigitLetterValue));
  s.push_back(CUTE(testCalcRemainder));
  s.push_back(CUTE(testCalcIntegerPart));
  ide_listener<> listener;
  makeRunner(listener)(s, "All rectangle tests");
  return 0;
}
