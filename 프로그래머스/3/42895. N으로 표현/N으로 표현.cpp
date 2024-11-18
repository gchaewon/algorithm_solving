#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;
    
    vector<set<int>> dp(9);
    
    // dp[i]는 i개의 N을 사용하여 만들 수 있는 수들의 집합
    dp[1].insert(N);
    
    for (int i = 2; i <= 8; i++) {
        // i개의 N을 사용하여 만들 수 있는 수들의 집합을 초기화
        for (int j = 1; j < i; j++) {
            for (auto a : dp[j]) {
                for (auto b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) {
                        dp[i].insert(a / b);
                    }
                }
            }
        }
        
        // N을 i번 연속해서 사용하는 경우 추가
        int num = 0;
        for (int k = 0; k < i; k++) {
            num = num * 10 + N;
        }
        dp[i].insert(num);
        
        // number를 찾으면 해당 i를 반환
        if (dp[i].find(number) != dp[i].end()) {
            return i;
        }
    }
    
    return -1;
}