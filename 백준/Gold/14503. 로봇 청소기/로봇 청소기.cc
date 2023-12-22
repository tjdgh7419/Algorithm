#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int room[52][52];
bool cleaned[52][52];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, r, c, d, cnt = 0;
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
		}
	}

	while (true)
	{
		if (cleaned[r][c] == false)
		{
			cleaned[r][c] = true;
			cnt++;
		}

		bool isClean = false;

		for (int i = 0; i < 4; i++)
		{
			d = (d + 3) % 4;
			int nx = r + dx[d];
			int ny = c + dy[d];

			if (room[nx][ny] == 0 && cleaned[nx][ny] == false)
			{
				r += dx[d];
				c += dy[d];
				isClean = true;
				break;
			}
		}

		if (!isClean)
		{
			int back = (d + 2) % 4;
			if (room[r + dx[back]][c + dy[back]] == 1) break;

			r += dx[back];
			c += dy[back];
		}
	}

	cout << cnt;
}
