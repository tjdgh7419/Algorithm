#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

int dp[10001];
int val[101];

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k = 0;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = val[i]; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - val[i]];
		}
	}

	cout << dp[k];
}
