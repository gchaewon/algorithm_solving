#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int i, int j, int n, int m, vector<vector<int>> &farm) {
    queue<pair<int, int>> q;
    farm[i][j] = 2;
    q.push({i, j});

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if (nx < 0 || nx >= n || ny < 0 || ny > m)
                continue;
            if (farm[nx][ny] != 1)
                continue;
            farm[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        int count = 0;
        cin >> m >> n >> k;
        vector<vector<int>> farm(n, vector<int>(m, 0));

        while (k--) {
            int x, y;
            cin >> y >> x;
            farm[x][y] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (farm[i][j] != 1)
                    continue;
                bfs(i, j, n, m, farm);
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}