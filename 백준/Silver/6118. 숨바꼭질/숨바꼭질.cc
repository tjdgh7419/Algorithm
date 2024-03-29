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

vector<vector<int>>link(20001);
bool visited[20001];
int hide_dist[20001];

void bfs(int st)
{
	visited[st] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(st, 0));

	while (!q.empty())
	{
		int now_node = q.front().first;
		int now_dist = q.front().second;
		q.pop();

		hide_dist[now_node] = now_dist;

		for (int next : link[now_node])
		{
			if (!visited[next])
			{
				visited[next] = true;
				q.push(make_pair(next, now_dist + 1));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, hide = -1, ans = 0, cnt = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int A_i, B_i;
		cin >> A_i >> B_i;

		link[A_i].push_back(B_i);
		link[B_i].push_back(A_i);
	}

	bfs(1);
	
	for (int i = 1; i < N; i++)
	{
		if (ans < hide_dist[i])
		{
			ans = hide_dist[i];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (ans == hide_dist[i])
		{
			if (hide == -1) hide = i;

			cnt++;
		}
	}
	cout << hide << " " << ans << " " << cnt;
}