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

int N, K, M;
vector<vector<int>>station(101001);
bool visited[101001];

int bfs(int st)
{
	queue<pair<int, int>> q;
	visited[st] = true;
	q.push(make_pair(st, 1));

	while (!q.empty())
	{
		int now_station = q.front().first;
		int now_step = q.front().second;
		q.pop();

		if (now_station == N) return now_step;

		for (int next : station[now_station])
		{
			if (!visited[next])
			{
				if (next > N)
				{
					visited[next] = true;
					q.push(make_pair(next, now_step));
				}
				else
				{
					visited[next] = true;
					q.push(make_pair(next, now_step + 1));
				}
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K >> M;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int hyper_Info;
			cin >> hyper_Info;

			station[hyper_Info].push_back(i + N);
			station[i + N].push_back(hyper_Info);
		}
	}

	cout << bfs(1);
}