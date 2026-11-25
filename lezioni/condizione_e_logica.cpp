#include <cstdio>
#include <iostream>
#include <ostream>
using namespace std;

int main() {
  double a = 0.2;
  double b = 0.1;
  double x = a + b;
  double diff = 0.3 - x;
  if (diff < 0)
    diff = -diff;
  if (diff < 1e-9)
    cout << "ciao" << endl;

  return 0;
  ;
}
