#include <bits/stdc++.h>

using namespace std;

int main() {
  int matrix[41*159];
  int start;
  int end;
  vector<int> starts;
  vector<int> adj[41*159];

  for (int y = 0; y < 41; y++) {
    string line;
    cin >> line;
    for (int x = 0; x < 159; x++) {
      int curr = x + y * 159;
      matrix[curr] = (int)(line[x] - 'a');
      if (matrix[curr] == 0) {
        starts.push_back(curr);
      }
      if (line[x] == 'S') {
        matrix[curr] = 0;
        starts.push_back(curr);
        start = curr;
      }
      if (line[x] == 'E') {
        matrix[curr] = (int)('z' - 'a');
        end = curr;
      }
    }
  }

  for (int y = 0; y < 41; y++) {
    for (int x = 0; x < 159; x++) {
      int curr = x + y * 159;
      int up = x + (y-1) * 159;
      int down = x + (y+1) * 159;
      int left = x-1 + y * 159;
      int right = x+1 + y * 159;
      if (y != 0)
        if (matrix[curr] - matrix[up] >= -1)
            adj[curr].push_back(up);

      if (x != 0)
        if (matrix[curr] - matrix[left] >= -1)
            adj[curr].push_back(left);

      if (y != 40)
        if (matrix[curr] - matrix[down] >= -1)
            adj[curr].push_back(down);

      if (x != 158)
        if (matrix[curr] - matrix[right] >= -1)
            adj[curr].push_back(right);
    }
  }
  int part1;
  int part2 = 1000;
  for (int i = 0; i < starts.size(); i++) {
    bool visited[41*159] = {};
    queue<int> q;
    int distance[41*159];
    int curr = starts[i];
    visited[curr] = true;
    distance[curr] = 0;
    q.push(curr);
    while (!q.empty()) {
      int s = q.front(); q.pop();
      for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        distance[u] = distance[s]+1;
        q.push(u);
      }
    }
    if (start == curr)
      part1 = distance[end];

    part2 = min(part2, distance[end]);
  }

  cout << "Part 1: " << part1 << "\n";
  cout << "Part 2: " << part2 << "\n";
}
