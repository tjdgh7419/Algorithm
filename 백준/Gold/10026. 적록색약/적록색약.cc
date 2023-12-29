#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
int board[502][502];
int board2[502][502];
bool visit[502][502];
bool visit2[502][502];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
queue<pair<int, int>> q;
int n = 0;

void BFS(int x, int y, int col, bool onColor)
{
	

	if (!onColor) 
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

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (!visit[nx][ny] && board[nx][ny] == col)
				{
					visit[nx][ny] = 1;
					q.push({ nx, ny });
				}
				else
				{
					continue;
				}
			}
		}
	}
	else
	{
		visit2[x][y] = 1;
		q.push({ x, y });
		while (!q.empty())
		{
			pair<int, int> p = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (!visit2[nx][ny] && board2[nx][ny] == col)
				{
					visit2[nx][ny] = 1;
					q.push({ nx, ny });
				}
				else
				{
					continue;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 0;
	int cnt2 = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char color;
			cin >> color;

			if (color == 'R')
			{
				board[i][j] = 1;
			}
			else if (color == 'G')
			{
				board[i][j] = 2;
			}
			else
			{
				board[i][j] = 3;
			}

			if (color == 'R' || color == 'G')
			{
				board2[i][j] = 1;
			}
			else
			{
				board2[i][j] = 2;
			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 1 && !visit[i][j])
			{
				cnt++;
				BFS(i, j, 1, 0);
			}
			else if (board[i][j] == 2 && !visit[i][j])
			{
				cnt++;
				BFS(i, j, 2, 0);
			}
			else if (board[i][j] == 3 && !visit[i][j])
			{
				cnt++;
				BFS(i, j, 3, 0);
			}

			if (board2[i][j] == 1 && !visit2[i][j])
			{
				cnt2++;
				BFS(i, j, 1, 1);
			}
			else if (board2[i][j] == 2 && !visit2[i][j])
			{
				cnt2++;
				BFS(i, j, 2, 1);
			}
		}
	}

	cout << cnt << ' ' << cnt2;
}