#include <bits/stdc++.h>

using namespace std;

int main() {
  string cmd;
  int reg = 1;
  int cycle = 1;
  int sum = 0;
  string result;

  while (cin >> cmd) {
    int arg;
    int c;
    if (cmd == "addx") {
      cin >> arg; c = 2;
    } else {
      arg = 0; c = 1;
    }

    for (int i = 0; i < c; i++) {
      int tmp = cycle % 40;
      if (tmp == reg 
        || tmp == reg +1 
        || tmp == reg + 2)  {
        result += "#";
      } else 
        result += ".";
      if (tmp == 20)
        sum += cycle * reg; 
      if (tmp == 0)
        result += "\n";
      cycle++;
    }
    reg += arg;
  }
  cout << "Part 1: " << sum << "\n";
  cout << "Part 2: \n" << result;
}
