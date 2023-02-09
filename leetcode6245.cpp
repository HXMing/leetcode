#include <cmath>
#include <iostream>
using namespace std;

int pivotInteger(int n) {
  int x2 = (n * n + n) / 2;
  int x = sqrt(x2);
  if (x * x == x2) {
    return x;
  }
  return -1;
}

int main() {
  int n;
  do {
    cin >> n;
    cout << pivotInteger(n) << "\n";
  } while (n > 0);
  return 0;
}
