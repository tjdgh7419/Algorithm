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

vector<vector<int>> link(51);
bool visited[51];
int candidate[51];

int bfs(int st)
{
	fill(visited, visited + 51, false);

	visited[st] = true;
	queue<pair<int, int>> q;
	int ans = 0;

	q.push(make_pair(st, 0));

	while (!q.empty())
	{
		int now_st = q.front().first;
		int now_score = q.front().second;
		q.pop();
		
		if (ans < now_score)
		{
			ans = now_score;
		}

		for (int next : link[now_st])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, now_score + 1));
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	int m = INT_MAX;
	int cnt = 1;
	cin >> N;

	while (true)
	{
		int u, v;
		cin >> u >> v;

		if (u == -1 && v == -1) break;

		link[u].push_back(v);
		link[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		int score = bfs(i);
		candidate[i] = score;
		
		if (m > score)
		{
			cnt = 1;
			m = score;
		}
		else if (m == score)
		{
			cnt++;
		}
	}

	cout << m << " " << cnt << '\n';

	for (int i = 1; i <= N; i++)
	{
		if (m == candidate[i])
		{
			cout << i << " ";
		}
	}
}