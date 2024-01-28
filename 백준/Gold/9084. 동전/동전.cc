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
int coin[21];
int dp[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 0;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int	n = 0;
		int amount = 0;

		memset(coin, 0, sizeof(coin));
		memset(dp, 0, sizeof(dp));

		dp[0] = 1;

		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];
		}

		cin >> amount;

		for (int i = 0; i < n; i++)
		{
			for (int j = coin[i]; j <= amount; j++)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}

		cout << dp[amount] << '\n';
	}
}