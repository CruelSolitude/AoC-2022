#include <bits/stdc++.h>

using namespace std;

int main() {
  char matrix[200][800] = {};
  string line;
  int m = 0;

  while (getline(cin,line)) {
    stringstream sstream = stringstream(line); 
    int x, y, xlim, ylim;
    string c;
    sstream >> x >> y >> c;
    while (sstream >> xlim >> ylim) {
      sstream >> c;
      int dy = ylim > y ? 1 : -1;
      int dx = xlim > x ? 1 : -1;
      for (; y != ylim; y += dy)
        matrix[y][x] = '#';
        m = max(m, y);
      for (; x != xlim; x += dx)
        matrix[y][x] = '#';
    matrix[y][x] = '#';
    }
  }
  // comment for part 1
  for (int i = 0; i < 800; i++) {
    matrix[m+2][i] = '#';
  }
  pair<int,int> s = {0, 500};
  int count;
  while (1) {
      int sy = s.first;
      int sx = s.second;
      if (matrix[sy+1][sx] == 0)
        s.first++;
      else if (matrix[sy+1][sx-1] == 0) {
        s.first++;
        s.second--;
      } else if (matrix[sy+1][sx+1] == 0) {
        s.first++;
        s.second++;
      } else {
        s = {0, 500};
        //if (sy == 199) break;
        matrix[sy][sx] = '+';
        if (matrix[0][500])
          break;
      }
  }

  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 800; j++) {
      if (matrix[i][j] == '+')
        count++;
    }
  }
  //cout << "Part 1: " << count << "\n";
  cout << "Part 2: " << count << "\n";
}
