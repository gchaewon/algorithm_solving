#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define X first;
#define Y second;
using namespace std;
int n, m;
vector<vector<int>> maps(501, vector<int> (501, -1));
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    int count = 0;
    
    while(!q.empty()){
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        
        for(auto d: dir){
            int nx = x+d.X;
            int ny = y+d.Y;
            if(nx <0 || nx >=n || ny <0 || ny >=m) continue;
            if(maps[nx][ny] !=1) continue;
            maps[nx][ny] = 2; // 방문처리
            q.push({nx, ny}); // 큐에 삽입
            count++;
        }
    }
    return count;
}

int main() {
    cin >> n >> m;
    vector<int> answer;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maps[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(maps[i][j]!=1) continue;
            answer.push_back(bfs(i, j));
        }
    }
    
     if(answer.size() == 0){
            cout << 0 << "\n" << 0;
        }
    else{
        sort(answer.rbegin(), answer.rend());
        cout << answer.size() <<"\n";
        !answer[0] ? cout << 1: cout << answer[0];
    }
    
    return 0;
}
