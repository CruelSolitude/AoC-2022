#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  int b, c, d;
  string lines[9];

  for (int i = 0 ; i < 9; i++) {
    getline(cin, line);
    reverse(line.begin(), line.end());
    lines[i] = line;
  }

  while (cin >> b >> c >> d) {
    string tmp = lines[c-1].substr(0, b);
    //reverse(tmp.begin(), tmp.end());
    lines[d-1] = tmp + lines[d-1];
    lines[c-1] = lines[c-1].substr(b);
  }

  for (int i = 0; i < 9; i++) {
    cout << lines[i][0];
  }
  cout << "\n";
}

