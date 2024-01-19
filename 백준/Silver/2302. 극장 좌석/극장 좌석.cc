#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>



using namespace std;

int VIP[41];
int dp[41];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m = 0;
	int start = 0;
	int ans = 1;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> VIP[i];
	}

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	for (int i = 0; i < m; i++)
	{
		int end = VIP[i];
		ans *= dp[end - start - 1];
		start = end;
	}

	ans *= dp[n - start];

	cout << ans;
}