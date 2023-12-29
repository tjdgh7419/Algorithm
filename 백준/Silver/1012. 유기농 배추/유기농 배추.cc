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
int n, m, k = 0;

void BFS(int x, int y)
{
	visit[x][y] = 1;
	q.push({ x, y });

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visit[nx][ny] || board[nx][ny] == 0) continue;

			visit[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		int cnt = 0;
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> y >> x;

			board[x][y] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && !visit[i][j])
				{
					cnt++;
					BFS(i, j);
				}
			}
		}
		cout << cnt << '\n';
	}
}