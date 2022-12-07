#include <bits/stdc++.h>

using namespace std;

int main() {
  string dir;
  string a;
  string cmd;
  vector<string> dir_stack;
  map<string, int> m;
  int un = 1;

  while (cin >> a) {
    if (a == "$") {
      cin >> cmd; 
      if (cmd == "cd") {
        cin >> dir;
        if (dir == "/") {
          dir_stack.clear();
          dir_stack.push_back(dir + "0");
        } else if (dir == "..") {
          dir_stack.pop_back();
        } else {
          dir_stack.push_back(dir + to_string(un));
          un++;
        }
      } else {
        int sum = 0;   
        while (cin >> a) {
          if (a != "dir") {
            sum += stoi(a);
          }
          cin >> a;
          cin.ignore(1, '\n');
          if (cin.peek() == '$') {
            break;
          }
        }
        for (auto b : dir_stack) {
          if (m.count(b)) {
            int tmp = (m.find(b))->second;
            m.erase(b);
            m.insert(pair<string,int>(b,tmp + sum));
          } else {
            m.insert(pair<string,int>(b,sum));
          }
        }
      }
    }  
  }
  int part1 = 0;
  int part2 = 70000000;
  int free = 70000000 - (m.find("/0"))->second;
  for (auto &i : m) {
    if (i.second >= 30000000 - free) {
      part2 = min(part2, i.second);
    }
    if (i.second <= 100000)
      part1 += i.second;
  } 
  cout << "Part 1: " << part1 << "\n";
  cout << "Part 2: " << part2 << "\n";
}

