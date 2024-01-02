#include <bits/stdc++.h>

vector<vector<int>> wallsAndGates(vector<vector<int>>& a, int n, int m) {
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                a[nr][nc] == INT_MAX) {
                a[nr][nc] = a[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return a;
}