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
    set<char> a;
    for (int i = 0; i < input.length() / 2; i++) {
      a.insert((char)input[i]);
    }
    for (int i = input.length() / 2 ; i < input.length(); i++) {
      if (a.count(input[i])) {
        sum += points(input[i]);
        break;
      }
    }
  }

  cout << "Part 1: " << sum << "\n";
  //cout << "Part 2: " << score2 << "\n";
}

