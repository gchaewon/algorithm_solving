#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, k;
    int sum = 0;
    cin >> n >> k;
    set<int> coins;
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;
        coins.insert(coin);
        if (coin <= k) {
            dp[coin] = 1;
        }
    }

    for (int i = *coins.begin(); i <= k; i++) {
        set<int> temp;
        if (dp[i] == 1) {
            continue;
        }
        for (auto coin : coins) {
            if (i - coin <= 0) {
                continue;
            }
            if (dp[i - coin] > 0) {
                temp.insert(dp[i - coin]);
            }
        }

        if (temp.size() != 0) {
            dp[i] = *temp.begin() + 1;
        } else {
            dp[i] = -1;
        }
    }

    // for (int i = 1; i < dp.size(); i++) {
    //     cout << i << " = " << dp[i] << "\n";
    // }
    cout << dp[k];

    return 0;
}