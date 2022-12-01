#include <bits/stdc++.h>

using namespace std;
int main() {
  string input;
  int sum = 0;
  vector<int> sums;

  while (getline(cin, input)) {
    if (input == "") {
      sums.push_back(sum);
      sum = 0;
    } else {
      sum += stoi(input);
    }
  }

  sort(sums.rbegin(), sums.rend());

  cout << "Part 1:" << sums[0] << "\n";
  cout << "Part 2:" << sums[0] + sums[1] + sums[2]<< "\n";
}
