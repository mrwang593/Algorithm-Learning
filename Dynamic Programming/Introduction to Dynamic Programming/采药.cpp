#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, M;  // T为总时间，M为草药数量
    cin >> T >> M;

    vector<int> time(M + 1), value(M + 1);
    for (int i = 1; i <= M; ++i) {
        cin >> time[i] >> value[i];  // 读取每种草药的时间和价值
    }

    // 一维dp数组，dp[j]表示时间不超过j时的最大价值
    vector<int> dp(T + 1, 0);

    // 0-1背包核心逻辑
    for (int i = 1; i <= M; ++i) {  // 遍历每种草药
        // 从后往前遍历时间，避免重复选取同一草药
        for (int j = time[i];j<=T; j++) {
            // 状态转移：选当前草药或不选，取最大值
            dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
        }
    }

    cout << dp[T] << endl;  // 输出最大时间内的最大价值
    return 0;
}
