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

string arr[25];
bool visit[25];
char seven[7];
int res = 0;

bool BFS() 
{
	queue <pair<int, int>> q;
	bool b_Visit[5][5];
	bool q_Visit[5][5];
	bool isInput = false;
	int cnt = 1;

	memset(b_Visit, false, sizeof(b_Visit));
	memset(q_Visit, false, sizeof(q_Visit));

	for (int i = 0; i < 25; i++)
	{
		if (visit[i])
		{
			int x = i / 5;
			int y = i % 5;

			b_Visit[x][y] = 1;

			if (!isInput)
			{
				q.push({ x, y });
				q_Visit[x][y] = 1;
				isInput = 1;
			}
		}
	}

	while (!q.empty())
	{
		if (cnt == 7) return true;

		pair<int, int> p = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
			if (b_Visit[nx][ny] && !q_Visit[nx][ny])
			{
				cnt++;
				q_Visit[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}

	return false;
}
void DFS(int idx, int cnt)
{
	if (cnt == 7)
	{
		int sCnt = 0;
		
		for (int i = 0; i < 25; i++)
		{
			if (visit[i])
			{
				int x = i / 5;
				int y = i % 5;

				if (arr[x][y] == 'S') sCnt++;
			}
		}

		if (sCnt >= 4 && BFS())
		{
			res++;
		}
	}
	
	for (int i = idx; i < 25; i++)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			DFS(i, cnt + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
	
	DFS(0, 0);

	cout << res;
}
