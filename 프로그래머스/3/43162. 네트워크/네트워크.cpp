#include <string>
#include <vector>
#include <queue>
#include <iostream>


using namespace std;


void bfs(vector<vector<int>> &computers, int n, int next, vector<int> &is_connect){
    queue<int> q;
    q.push(next); // 다음 컴퓨터 번호 넣기
    cout << next << "\n";
    while(!q.empty()){
        int pre = q.front();
        q.pop();
        
        for(int i=0; i<n; i++){
            if(computers[pre][i]!=1){
                continue;
            }
            if(i!= next && computers[pre][i]){
                cout << "방문합니다." << i  <<"\n";
                computers[pre][i] = 2;
                computers[i][pre] = 2;
                is_connect[pre] = 1;
                is_connect[i] = 1;
                
                q.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> is_connect(n, 0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(computers[i][j]==1 && i!=j){
                computers[i][j]=computers[j][i]=2;
                is_connect[i] = 1;
                is_connect[j] = 1;
                bfs(computers, n, j, is_connect);
                answer++;
            }
        }
    }
    for(auto i: is_connect){
        cout << i << " ";
        if(!i){
            answer++;
        }
    }
    
    return answer;
}