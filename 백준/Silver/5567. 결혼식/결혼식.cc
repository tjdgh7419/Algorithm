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

vector<vector<int>> link(501);
bool visited[501];
int ans = 0;

void dfs(int now, int depth)
{
	if (depth == 2) return;

	

	for (int next : link[now])
	{
		visited[next] = true;
		dfs(next, depth + 1);
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
	visited[1] = true;
	dfs(1, 0);

	for (int i = 2; i <= n; i++) {
		if (visited[i]) {
			ans++;
		}
	}

	cout << ans;
}