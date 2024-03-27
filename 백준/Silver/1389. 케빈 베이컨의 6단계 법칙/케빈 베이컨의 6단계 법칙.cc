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

vector<vector<int>>link(101);
bool visited[101];

int bfs(int st)
{
	fill(visited, visited + 101, false);

	visited[st] = true;

	int kevin = 0;
	queue<pair<int, int>> q;

	q.push(make_pair(st, 0));

	while (!q.empty())
	{
		int now = q.front().first;
		int score = q.front().second;
		q.pop();

		kevin += score;

		for (int next : link[now])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, score + 1));
			}
		}
	}
	return kevin;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, MIN = INT_MAX, ans = 0;
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
		int kevin_bacon = bfs(i);

		if (MIN > kevin_bacon)
		{
			MIN = kevin_bacon;
			ans = i;
		}
	}

	cout << ans;
}