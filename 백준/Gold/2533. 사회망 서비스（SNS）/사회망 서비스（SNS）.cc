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

vector<vector<int>> link(1000001);
bool visited[1000001];
int dp[1000001][2];

void dfs(int st)
{
	visited[st] = true;
	dp[st][0] = 1;
	for (int next : link[st])
	{
		if (!visited[next])
		{
			dfs(next);
			dp[st][1] += dp[next][0];
			dp[st][0] += min(dp[next][1], dp[next][0]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		link[u].push_back(v);
		link[v].push_back(u);
	}

	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
}