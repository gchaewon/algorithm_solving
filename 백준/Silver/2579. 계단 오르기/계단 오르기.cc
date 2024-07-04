#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(301, 0);
    vector<vector<int>> dp(301, vector<int>(3, 0));

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dp[1][1] = v[1];
    dp[1][2] = 0;
    dp[2][1] = v[2];
    dp[2][2] = v[1] + v[2];

    for (int i = 3; i <= n; i++) {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + v[i];
        dp[i][2] = dp[i - 1][1] + v[i];
    }

    cout << max(dp[n][1], dp[n][2]);
}
