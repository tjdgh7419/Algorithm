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

vector<vector<int>>link(10001);
int computer[10001];
bool visited[10001];
int ans = 0;

void dfs(int st, int depth)
{
	visited[st] = true;
	
	for (int next : link[st])
	{
		if (!visited[next])
		{
			dfs(next, depth + 1);
			ans++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, MAX = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		link[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		fill(visited, visited + 10001, false);
		ans = 0;

		dfs(i, 0);
		computer[i] = ans;

		if (MAX < ans)
		{
			MAX = ans;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (computer[i] == MAX)
		{
			cout << i << " ";
		}
	}
}