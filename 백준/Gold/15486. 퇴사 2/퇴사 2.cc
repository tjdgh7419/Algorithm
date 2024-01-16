#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;
int dp[1500001];
vector<pair<int, int>> vec;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, res = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int t, p;
		cin >> t >> p;

		vec.push_back({t, p});
	}
	vec.push_back({0, 0});

	for (int i = 1; i <= n + 1; i++)
	{
		res = max(res, dp[i]);
		if (i + vec[i - 1].first <= n + 1 )
		{		
			dp[i + vec[i - 1].first] = max(dp[i + vec[i - 1].first], res + vec[i - 1].second);
		}
	}

	cout << res;
}