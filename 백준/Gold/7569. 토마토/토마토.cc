#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
int board[102][102][102];
int visit[102][102][102];

int dx[] = { 0, 0, 1, -1, 0, 0 };
int dy[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

queue<pair<pair<int, int>, int>> q;
int n, m, h, cnt = 0;

void BFS()
{
	while (!q.empty())
	{
		int z = q.front().first.first;
		int x = q.front().first.second;
		int y = q.front().second;

		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h) continue;
			if (visit[nz][nx][ny] == -1 && board[nz][nx][ny] == 0)
			{
				visit[nz][nx][ny] = visit[z][x][y] + 1;
				q.push({ { nz, nx }, ny });
			}			
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int day = 0;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{			
			for (int k = 0; k < m; k++)
			{
				cin >> board[i][j][k];

				if (board[i][j][k] == 1)
				{
					q.push({ {i, j} , k });
					visit[i][j][k] = 1;
				}
				else if (board[i][j][k] == 0)
				{
					visit[i][j][k] = -1;
				}
			}
		}
	}

	BFS();

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (visit[i][j][k] == -1 && board[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}

				day = max(day, visit[i][j][k]);
			}
		}
	}
	
	cout << day - 1;
}

