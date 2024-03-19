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

vector<vector<int>> link(100001);
int p_num[100001];
int dp[100001];

void dfs(int st)
{
	for (int next : link[st])
	{
		if (p_num[st] == next) continue;
		dp[next] += dp[st];
		dfs(next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int n_num;
		cin >> n_num;

		p_num[i] = n_num;

		if (n_num != -1)
		{
			link[n_num].push_back(i);
			link[i].push_back(n_num);
		}
	}

	for (int j = 0; j < m; j++)
	{
		int i, w;
		cin >> i >> w;

		dp[i] += w;
	}

	dfs(1);

	for (int i = 1; i <= n; i++)
	{
		cout << dp[i] << " ";
	}
}