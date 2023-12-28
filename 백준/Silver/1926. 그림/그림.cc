#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
int board[502][502];
bool visit[502][502];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;
int n, m = 0;

int BFS(int x, int y)
{
	int cnt = 0;
	q.push({ x, y });
	visit[x][y] = 1;

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		cnt++;

		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || board[nx][ny] != 1) continue;
			
			visit[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int max = 0;
	int num = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && visit[i][j] == 0)
			{
				num++;
				int a = BFS(i, j);
				if (max < a)
				{
					max = a;
				}
			}
		}
	}

	cout << num << '\n' << max;
}
