#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define X first;
#define Y second;

using namespace std;

vector<vector<int>> v(101, vector<int>(101, 1));
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;

int bfs(int i, int j) {
    int area = 0;
    queue<pair<int, int>> q;
    q.push({i, j});
    v[i][j] = 2;

    while (!q.empty()) {
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();

        for (auto d : dir) {
            int nx = x + d.X;
            int ny = y + d.Y;

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (v[nx][ny] != 1)
                continue;

            q.push({nx, ny});
            v[nx][ny] = 2;
            area++;
        }
    }
    return area;
}
int main() {
    int k;
    vector<int> answer;
    cin >> m >> n >> k;

    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = m - y2; i < m - y1; i++) {
            for (int j = x1; j < x2; j++) {
                if (v[i][j] == 0)
                    continue;
                v[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] != 1)
                continue;
            answer.push_back(bfs(i, j) + 1);
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (auto i : answer) {
        cout << i << " ";
    }

    return 0;
}