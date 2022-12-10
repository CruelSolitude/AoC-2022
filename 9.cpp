#include <bits/stdc++.h>

using namespace std;

int main() {
  pair<int,int> ropes[10];
  for (int i = 0; i < 10; i++) {
    ropes[i] = make_pair(0,0);
  }
  string cmd;
  int steps;
  set<pair<int,int>> visited1;
  set<pair<int,int>> visited9;

  visited1.insert(make_pair(0,0));
  visited9.insert(make_pair(0,0));

  while (cin >> cmd >> steps) {
    for (int i = 0; i < steps; i++) {
      for (int i = 1; i < 10; i++) {
        if (i == 1) {
          if (cmd == "L")
            ropes[i-1].first--;
          if (cmd == "R")
            ropes[i-1].first++;
          if (cmd == "D")
            ropes[i-1].second--;
          if (cmd == "U")
            ropes[i-1].second++;
        }
        int dx = ropes[i-1].first - ropes[i].first;
        int dy = ropes[i-1].second - ropes[i].second;
        double norm = sqrt(dx * dx + dy * dy);
        if (norm <= sqrt(2));
        else {
            if (dx != 0) 
            ropes[i].first += dx >= 0 ? 1: -1;
            if (dy != 0)
            ropes[i].second += dy >= 0 ? 1: -1;
        }

      }
      visited1.insert(ropes[1]);
      visited9.insert(ropes[9]);
    }
  }
  cout << visited1.size() << "\n";
  cout << visited9.size() << "\n";
}
