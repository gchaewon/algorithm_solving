#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;

using namespace std;

int main() {
    int t;
    vector<pair<int, int>> dir = {{2, -1},  {2, 1},  {1, -2},  {1, 2},
                                  {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}};

    cin >> t;

    while (t--) {
        int l;
        vector<vector<int>> v(301, vector<int>(301, 0));
        vector<vector<int>> dist(301, vector<int>(301, -1));
        queue<pair<int, int>> q;
        cin >> l;

        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;

        q.push({sx, sy});
        v[sx][sy] = 2;
        dist[sx][sy] = 0;

        while (!q.empty()) {
            int x = q.front().X;
            int y = q.front().Y;
            q.pop();

            if (x == dx && y == dy) {
                cout << dist[x][y] << "\n";
                break;
            }

            for (auto d : dir) {
                int nx = x + d.X;
                int ny = y + d.Y;

                if (nx < 0 || nx >= l || ny < 0 || ny >= l)
                    continue;
                if (v[nx][ny] != 0)
                    continue;

                q.push({nx, ny});
                v[nx][ny] = 2;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }

    return 0;
}