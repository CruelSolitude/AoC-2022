#include <bits/stdc++.h>

using namespace std;

int points(char a) {
  if (a > 96) {
    return a - 'a' + 1;
  }
    return a - 'A' + 27;
}

int main() {
  string input;
  int sum = 0;

  while (cin >> input) {
    vector<char> v(100);
    set<char> a(input.begin(), input.end());
    cin >> input;
    set<char> b(input.begin(), input.end());
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), v.begin());
    cin >> input;
    set<char> c(input.begin(), input.end());
    set<char> d(v.begin(), v.end());
    set_intersection(c.begin(), c.end(), d.begin(), d.end(), v.begin());
    sum += points(v[0]);
  }
  //cout << "Part 1: " << sum << "\n";
  cout << "Part 2: " << sum << "\n";
}

