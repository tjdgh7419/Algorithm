#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;
string board[1002];
int fDist[1002][1002];
int jDist[1002][1002];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


queue<pair<int, int>> jQ;
queue<pair<int, int>> fQ;
int r, c = 0;

void FBFS()
{
	while (!fQ.empty())
	{
		pair<int, int> p = fQ.front();
		fQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (fDist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			fDist[nx][ny] = fDist[p.first][p.second] + 1;
			fQ.push({ nx, ny });
		}
	}
}

void JBFS()
{
	while (!jQ.empty())
	{
		pair<int, int> p = jQ.front();
		jQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			{
				cout << jDist[p.first][p.second] + 1;
				return;
			}

			if (board[nx][ny] == '#' || jDist[nx][ny] >= 0) continue;
			if (fDist[nx][ny] != -1 && fDist[nx][ny] <= jDist[p.first][p.second] + 1) continue;
			jDist[nx][ny] = jDist[p.first][p.second] + 1;
			jQ.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			fDist[i][j] = -1;
			jDist[i][j] = -1;
		}
	}

	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'F')
			{
				fQ.push({ i, j });
				fDist[i][j] = 0;
			}
			else if (board[i][j] == 'J')
			{
				jQ.push({ i, j });
				jDist[i][j] = 0;
			}
		}
	}

	FBFS();
	JBFS();
}