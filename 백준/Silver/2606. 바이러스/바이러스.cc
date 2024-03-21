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

vector<vector<int>> link(101);
bool visted[101];
int ans = 0;
void dfs(int st)
{
	visted[st] = true;

	for (int next : link[st])
	{
		if (!visted[next])
		{
			dfs(next);
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		link[u].push_back(v);
		link[v].push_back(u);
	}

	dfs(1);
	cout << ans;
}