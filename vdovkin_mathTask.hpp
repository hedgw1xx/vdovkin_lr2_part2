#ifndef _VDOVKIN_MATHTASK_HPP_
#define _VDOVKIN_MATHTASK_HPP_

#include <functional>
#include <iostream>
#include <string>

using namespace std;

inline bool UserInput(string input) {
  if (input.empty() || input[0] == '-')
    return false;
  size_t pos;
  try {
    int number = stoi(input, &pos);
    return pos == input.size();
  } catch (...) {
    return false;
  }
  return true;
}

function<void()> inline EnterNumber(int &varLink, string label) {
  return [&varLink, label]() {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    while (!UserInput(raw_input)) {
      cout << label;
      getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
  };
}

inline int CalcRemainder(int a, int b, int c) { return (a + b) % c; }

inline int CalcIntegerPart(int a, int b, int c) { return (a + b) / c; }

#endif
