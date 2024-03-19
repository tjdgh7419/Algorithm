#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <map>

using namespace std;

int p_num[100001];
int dp[100001];
int n, m;

void solve()
{
	for (int j = 0; j < m; j++)
	{
		int i, w;
		cin >> i >> w;

		dp[i] += w;
	}

	cout << dp[0] << " ";
	for (int i = 2; i <= n; i++)
	{
		dp[i] += dp[p_num[i]];
		cout << dp[i] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int n_num;
		cin >> n_num;

		p_num[i] = n_num;
	}

	solve();
}
