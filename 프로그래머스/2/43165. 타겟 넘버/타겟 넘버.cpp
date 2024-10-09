#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int n = numbers.size();
    vector<vector<int>> comb(n+1);
    
    comb[0].push_back(0);
    
    for(int i=0; i< n; i++){
        for(auto pre: comb[i]){
            int a = pre+numbers[i];
            int b = pre-numbers[i];
            
            comb[i+1].push_back(a);
            comb[i+1].push_back(b);
            
            if(i==n-1){
                if(a == target || b == target){
                    answer++;
                }
            }
        }
    }
    
    
    return answer;
}