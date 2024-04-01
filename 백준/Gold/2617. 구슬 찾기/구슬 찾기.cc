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

vector<vector<int>>light(100);
vector<vector<int>>heavy(100);
bool visited[100];

int cnt = 0;
int ans = 0;

int bfs(vector<vector<int>> v, int st)
{
	fill(visited, visited + 100, false);

	visited[st] = true;
	queue<int> q;
	q.push(st);

	int cnt = 0;

	while (!q.empty())
	{
		int now_node = q.front();
		q.pop();

		for (int next : v[now_node])
		{
			if (!visited[next])
			{
				visited[next] = true;
				cnt++;
				q.push(next);
			}
		}
	}	
	
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		light[u].push_back(v);
		heavy[v].push_back(u);
	}

	for (int i = 1; i <= N; i++)
	{		
		if (bfs(light, i) >= (N + 1) / 2 || bfs(heavy, i) >= (N + 1) / 2) ans++;
	}

	cout << ans;
}