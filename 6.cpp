#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  int count = 0;
  unordered_set<char> a;

  //change 14 to 4 for part 1
  getline(cin, line);
  for (int i = 0; i < line.size(); i++) {
    for (int j = 0; j < 14; j++) {
      a.insert(line[j + i]);
    }
    if (a.size() == 14) {
      count = i + 14;
      break;
    }
    a.clear();
  }

  cout << count << "\n";
}

