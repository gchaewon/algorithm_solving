#include <string>
#include <vector>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> v) {
    int answer = 0;
    string pre;
    int n = begin.length();
    vector<bool> is_finished(n, false); // n자리 알파벳이 타겟과 일치하는지 여부
    set<string> words;
    queue<string> q;
    
    for(auto word: v){
        words.insert(word);
    }
    
    q.push(begin);
    
    while(words.size()>=0 && !q.empty()){
        pre = q.front();
        q.pop();
        
        if(pre == target){
            return answer;
        }
        
        for(auto word: words){
            int diff = 0;
            int change = 0;
            for(int i=0; i<n; i++){
                if(diff >= 2){
                    break;
                }
                if(word[i] != pre[i]){
                    diff++;
                    change = i;
                }
            }
            if(diff==1){
                if(is_finished[change]){
                    break;
                }
                if(target[change]==word[change]){
                    is_finished[change] = true;
                }
                q.push(word);
                words.erase(word);
                answer++;
                break;
            }
        }
    }
    
    return 0;
}