#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  int sum1 = 0;
  int sum2 = 0;

  while (cin >> a >> b >> c >> d) {
    if ((a <= c && b >= d) || (c <= a && d >= b)) {
      sum1 += 1; 
    }
    if ((a <= d && b >= d) || (c <= b && d >= b)) {
      sum2 += 1;
    }

  }
  cout << "Part 1: " << sum1 << "\n";
  cout << "Part 2: " << sum2 << "\n";
}

