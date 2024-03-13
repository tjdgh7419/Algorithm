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

vector<vector<pair<int, int>>> node(1005);
bool visited[1005];

int bfs(int f, int s)
{
	fill(visited, visited + 1005, false);
	queue<pair<int, int>> q;
	visited[f] = true;
	q.push(make_pair(f, 0));

	while (!q.empty())
	{
		int cur_f = q.front().first;
		int cur_d = q.front().second;
		q.pop();

		if (cur_f == s) return cur_d;

		for (int i = 0; i < node[cur_f].size(); i++)
		{
			int nex_f = node[cur_f][i].first;
			int nex_d = node[cur_f][i].second;

			if (!visited[nex_f])
			{
				visited[nex_f] = true;
				q.push(make_pair(nex_f, nex_d + cur_d));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N - 1; i++)
	{
		int f, s, d;
		cin >> f >> s >> d;
		node[f].push_back(make_pair(s, d));
		node[s].push_back(make_pair(f, d));
	}

	for (int i = 0; i < M; i++)
	{
		int f, s;
		cin >> f >> s;

		cout << bfs(f, s) << '\n';
	}
}
