#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    vector<int> dp(12, 0);
    \
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i=4; i<=11; i++){
        for(int j=1; j<=3; j++){
            dp[i] += dp[i-j];
        }
    }
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    
    return 0;
}