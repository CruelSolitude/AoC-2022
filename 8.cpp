#include <bits/stdc++.h>

using namespace std;
int check(int, int, int, string*);


int main() {
  int size = 99;
  string grid[size];
  int i = 0; int count = 0;
  while(cin >> grid[i++]);
  
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (x == 0 || y == 0 || x == size-1 || y == size-1) {
        //count++;
      } else {
        string tmp(1, grid[y][x]);
        count = max(count,check(x,y,stoi(tmp), grid));
      }

    }
  }
  //cout << "Part 1: " << count << "\n";
  cout << "Part 2: " << count << "\n";
}

int check(int x, int y, int z, string *grid) {
  int a,b,c,d;
  a = b = c = d = 0;
  for (int i = y-1; i >= 0; i--) {
    string tmp(1, grid[i][x]);
    a++;
    if (stoi(tmp) >= z)
      break;
  }
  for (int i = y+1; i < 99; i++) {
    string tmp(1, grid[i][x]);
    b++;
    if (stoi(tmp) >= z)
      break;
  }
  for (int i = x-1; i >= 0; i--) {
    string tmp(1, grid[y][i]);
    c++;
    if (stoi(tmp) >= z)
      break;
  }
  for (int i = x+1; i < 99; i++) {
    string tmp(1, grid[y][i]);
    d++;
    if (stoi(tmp) >= z)
      break;
  }
  return a*b*c*d;
}

