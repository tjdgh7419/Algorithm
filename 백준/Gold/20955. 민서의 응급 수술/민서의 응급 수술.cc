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

vector<vector<int>> link (100001);
bool visited[100001];
bool cycle[100001];
int cycle_cnt = 0;

void dfs(int st, int prev)
{
	visited[st] = true;

	for (int i : link[st])
	{
		if (!visited[i])
		{
			dfs(i, st);
		}
		else if (!cycle[i] && prev != i)
		{
			cycle_cnt++;
		}
	}
	cycle[st] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, ans = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		link[u].push_back(v);
		link[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			dfs(i, 0);
			ans++;
		}
	}

	cout << (ans - 1) + cycle_cnt;
}


