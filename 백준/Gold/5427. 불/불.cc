#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
string board[1002];
int fDist[1002][1002];
int jDist[1002][1002];

queue<pair<int, int>> fQ;
queue<pair<int, int>> jQ;
int w, h = 0;

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

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (fDist[nx][ny] >= 0 || board[nx][ny] == '#') continue;

			fDist[nx][ny] = fDist[p.first][p.second] + 1;
			fQ.push({nx, ny});
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

			if (nx < 0 || ny < 0 || nx >= h || ny >= w)
			{
				cout << jDist[p.first][p.second] + 1 << '\n';
				return;
			}

			if (board[nx][ny] == '#' || jDist[nx][ny] >= 0) continue;
			if (fDist[nx][ny] != -1 && fDist[nx][ny] <= jDist[p.first][p.second] + 1) continue;

			jDist[nx][ny] = jDist[p.first][p.second] + 1;
			jQ.push({nx, ny});
		}
	}

	cout << "IMPOSSIBLE" << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t = 0;

	cin >> t;

	while (t--)
	{
		cin >> w >> h;

		for (int i = 0; i < h; i++)
		{
			fill(fDist[i], fDist[i] + w, -1);
			fill(jDist[i], jDist[i] + w, -1);
		}

		for (int i = 0; i < h; i++)
		{
			cin >> board[i];
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (board[i][j] == '*')
				{
					fQ.push({ i, j });
					fDist[i][j] = 0;
				}
				else if (board[i][j] == '@')
				{
					jQ.push({ i, j });
					jDist[i][j] = 0;
				}
			}
		}

		FBFS();
		JBFS();

		while (!jQ.empty()) jQ.pop();
		while (!fQ.empty()) fQ.pop();
	}
}