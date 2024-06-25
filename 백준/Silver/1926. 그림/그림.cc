#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> answer;
    vector<vector<int>> v(n, vector<int> (m, 0));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v[i][j]!=1){
                continue;
            }
            else{
                int count = 0;
                queue<vector<int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int x = q.front()[0];
                    int y = q.front()[1];
                    q.pop();
                    
                    if(x+1<n && v[x+1][y] == 1){
                        q.push({x+1, y});
                        v[x+1][y] = 2;
                        count++;
                    }
                    if(x-1>=0 && v[x-1][y] == 1){
                        q.push({x-1, y});
                        v[x-1][y] = 2;
                        count++;
                    }
                    if(y+1<m && v[x][y+1] == 1){
                        q.push({x, y+1});
                        v[x][y+1] = 2;
                        count++;
                    }
                    if(y-1>=0 && v[x][y-1] == 1){
                        q.push({x, y-1});
                        v[x][y-1] = 2;
                        count++;
                    }
                }
                answer.push_back(count);
            }
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