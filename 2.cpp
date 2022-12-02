#include <bits/stdc++.h>

using namespace std;
int main() {
  char a;
  char b;
  int score = 0, score2 = 0;
  int word[3] = {1,2,3};
  int round[3] = {0,3,6};

  while (cin >> a >> b) {
    int y = b - 'X';
    int x = a - 'A';
    score += word[y] + round[(y-x+4)%3];
    score2 += word[(x+y+2)%3] + round[y];
  }

  cout << "Part 1: " << score << "\n";
  cout << "Part 2: " << score2 << "\n";
}
