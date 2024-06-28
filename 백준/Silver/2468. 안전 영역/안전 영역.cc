#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;
using namespace std;

int n;
vector<vector<int>> v(101, vector<int>(101, -1));
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs(int i, int j, int k, vector<vector<int>> &maps) {
    queue<pair<int, int>> q;
    q.push({i, j});
    maps[i][j] = 0;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (maps[nx][ny] < k)
                continue;

            q.push({nx, ny});
            maps[nx][ny] = 0;
        }
    }
}
int main() {
    int t = 0, answer = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            t = max(t, v[i][j]);
        }
    }

    for (int k = 1; k <= t; k++) {
        int count = 0;
        vector<int> area;
        vector<vector<int>> maps = v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maps[i][j] < k)
                    continue;
                bfs(i, j, k, maps);
                count++;
            }
        }
        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}