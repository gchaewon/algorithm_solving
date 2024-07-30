#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    int answer = 0;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i + 1];
    }
    dp[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += arr[i];
    }

    sort(dp.rbegin(), dp.rend());
    cout << dp[0];
    // for (int i = 1; i <= n; i++) {
    //     cout << "dp[" << i << "] = " << dp[i] << "\n";
    // }
    return 0;
}