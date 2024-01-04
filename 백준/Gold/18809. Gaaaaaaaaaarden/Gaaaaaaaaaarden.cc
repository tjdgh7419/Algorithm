#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int n, m, g, r = 0;
int board[51][51];
int copy_Board[51][51];
int check_Green[51][51];
int check_Red[51][51];
int check_land[51][51];

vector<pair<int, int>>land;
vector<int> green, red;

typedef struct qu
{
	int x;
	int y;
	int t;
}qu;

int ans;


void BFS()
{
	queue<qu> G_q;
	queue<qu> R_q;
	int flower = 0;

	for (int i = 0; i < g; i++)
	{
		int x = green[i];
		copy_Board[land[x].first][land[x].second] = 3;
		check_Green[land[x].first][land[x].second] = 1;
		G_q.push({ land[x].first, land[x].second, 1 });
	}

	for (int i = 0; i < r; i++)
	{
		int x = red[i];
		copy_Board[land[x].first][land[x].second] = 4;
		check_Red[land[x].first][land[x].second] = 1;
		R_q.push({ land[x].first, land[x].second, 1 });
	}

	while (!G_q.empty() || !R_q.empty())
	{
		int G_size = G_q.size();
		int R_size = R_q.size();

		for (int k = 0; k < G_size; k++)
		{
			int x = G_q.front().x;
			int y = G_q.front().y;
			int t = G_q.front().t;
			G_q.pop();
			if (copy_Board[x][y] == -1) continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

				if (check_Green[nx][ny] == 0 && (copy_Board[nx][ny] == 1 || copy_Board[nx][ny] == 2))
				{
					check_Green[nx][ny] = t + 1;
					G_q.push({ nx, ny, t + 1 });
					copy_Board[nx][ny] = 3;
				}

			}
		}

		for (int k = 0; k < R_size; k++)
		{
			int x = R_q.front().x;
			int y = R_q.front().y;
			int t = R_q.front().t;
			R_q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;

				if (check_Red[nx][ny] == 0 && (copy_Board[nx][ny] == 1 || copy_Board[nx][ny] == 2))
				{
					check_Red[nx][ny] = t + 1;
					R_q.push({ nx, ny, t + 1 });
					copy_Board[nx][ny] = 4;
				}

				else if (check_Red[nx][ny] == 0 && copy_Board[nx][ny] == 3)
				{
					if (check_Green[nx][ny] == t + 1)
					{
						copy_Board[nx][ny] = -1;
						check_Red[nx][ny] = t + 1;
					}
				}

			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (copy_Board[i][j] == -1) flower++;
		}
	}
	ans = max(ans, flower);
}

void reset_board()
{
	memset(check_Green, 0, sizeof(check_Green));
	memset(check_Red, 0, sizeof(check_Red));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			copy_Board[i][j] = board[i][j];
		}
	}
}

void select_red(int start, int cnt)
{
	if (cnt == r)
	{
		BFS();
		reset_board();
	}
	else
	{
		for (int i = start; i < land.size(); i++)
		{
			if (check_land[land[i].first][land[i].second] == 0)
			{
				check_land[land[i].first][land[i].second] = 1;
				red.push_back(i);
				select_red(i, cnt + 1);
				check_land[land[i].first][land[i].second] = 0;
				red.pop_back();
			}
		}
	}
}

void select_green(int start, int cnt)
{
	if (cnt == g)
	{
		select_red(0, 0);
	}
	else
	{
		for (int i = start; i < land.size(); i++)
		{
			if (check_land[land[i].first][land[i].second] == 0)
			{
				check_land[land[i].first][land[i].second] = 1;
				green.push_back(i);
				select_green(i, cnt + 1);
				check_land[land[i].first][land[i].second] = 0;
				green.pop_back();
			}
		}
	}
}

void solve()
{
	select_green(0, 0);
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> g >> r;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
			copy_Board[i][j] = board[i][j];

			if (board[i][j] == 2) land.push_back({ i, j });
		}
	}

	solve();
	return 0;
}