#include "vdovkin_mathTask.hpp"

int main() {
  int a, b, c;
  EnterNumber(a, "Enter number A: ")();
  EnterNumber(b, "Enter number B: ")();
  EnterNumber(c, "Enter number C: ")();
  int _remainder = CalcRemainder(a, b, c);
  int _integerPart = CalcIntegerPart(a, b, c);
  cout << "Remainder: " << _remainder << endl
       << "Integer part: " << _integerPart << endl;
}
