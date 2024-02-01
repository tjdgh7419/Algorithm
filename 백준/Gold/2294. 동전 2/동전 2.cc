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

int coin[101];
int dp[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	fill(begin(dp), end(dp), 10001);
	dp[0] = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = coin[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 10001) cout << -1;
	else cout << dp[k];
}