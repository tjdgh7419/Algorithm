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

vector<vector<int>> G(101);
int matrix[101][101];
bool visited[101];

void bfs(int st)
{
	fill(visited, visited + 101, false);

	queue<int> q;
	visited[st] = true;
	q.push(st);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int next : G[now])
		{
			if (!visited[next] || next == st)
			{
				matrix[st][next] = 1;
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int node;
			cin >> node;

			if (node == 1)
			{
				G[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		bfs(i);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}
}