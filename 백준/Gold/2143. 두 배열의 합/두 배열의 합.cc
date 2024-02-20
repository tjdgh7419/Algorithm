#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long T, n, m, ans = 0;
    cin >> T >> n;

    // Read array A
    vector<long long> n_arr(n);
    for (int i = 0; i < n; i++) {
        cin >> n_arr[i];
    }

    cin >> m;

    // Read array B
    vector<long long> m_arr(m);
    for (int i = 0; i < m; i++) {
        cin >> m_arr[i];
    }

    // Calculate subarray sums for arrays A and B
    vector<long long> n_sums, m_sums;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += n_arr[j];
            n_sums.push_back(sum);
        }
    }
    for (int i = 0; i < m; i++) {
        long long sum = 0;
        for (int j = i; j < m; j++) {
            sum += m_arr[j];
            m_sums.push_back(sum);
        }
    }

    // Sort the sums of array B
    sort(m_sums.begin(), m_sums.end());

    // Count valid pairs
    for (int i = 0; i < n_sums.size(); i++) {
        long long target = T - n_sums[i];
        auto lower = lower_bound(m_sums.begin(), m_sums.end(), target);
        auto upper = upper_bound(m_sums.begin(), m_sums.end(), target);
        ans += (upper - lower);
    }

    cout << ans << endl;

    return 0;
}
