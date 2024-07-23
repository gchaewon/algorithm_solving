#include <iostream>
#include <vector>

#define MOD 10007
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(10, 0));

    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) {
        result = (result + dp[n][i]) % MOD;
    }

    cout << result << endl;
    return 0;
}
