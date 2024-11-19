#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    int K, L;
    int count = 0;
    unordered_map<string, int> m;
    map<int, string> ans;

    cin >> K >> L;

    while (L--) {
        string temp;
        cin >> temp;
        if (m.find(temp) != m.end()) {
            m[temp] = count++;
            continue;
        }
        m.insert({temp, count++});
    }

    for (auto i : m) {
        ans.insert({i.second, i.first});
    }

    count = 0;
    for (auto i : ans) {
        if (count >= K) {
            break;
        }
        cout << i.second << "\n";
        count++;
    }

    return 0;
}