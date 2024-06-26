#include <iostream>
#include <vector>
#include <queue>

#define X first;
#define Y second;

using namespace std;
vector<vector<int>> maps(101, vector<int>(101, -1));
vector<vector<int>> dist(101, vector<int>(101, -1));

vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0},{0, -1}, };
int N, M;

int main() {
    queue<pair<int, int>> q;
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        string line;
        cin >> line;
        for(int j=0; j<M; j++){
            maps[i][j] = line[j]-'0';
        }
    }
    
    q.push({0, 0});
    maps[0][0] = 2;
    dist[0][0] = 0;
    
    while(!q.empty()){
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        
        if((x == N-1) && (y == M-1)){
            cout << dist[x][y]+1;
            return 0;
        }
        
        for(auto d: dir){
            int nx = x+d.X;
            int ny = y+d.Y;
            if(nx >= N || nx <0 || ny >=M || ny <0)continue;
            if(maps[nx][ny] !=1){
                continue;
            }
            q.push({nx, ny});
            maps[nx][ny] = 2;
            dist[nx][ny] = dist[x][y]+1;
        }
    }
    
    return 0;
}