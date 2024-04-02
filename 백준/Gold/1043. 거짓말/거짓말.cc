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

vector<vector<int>>link(51);
vector<vector<int>>input(51);

bool visited[51];
bool v_trust[51];

void dfs(int st)
{
	visited[st] = true;
	v_trust[st] = true;
	for (int next : link[st])
	{
		if (!visited[next])
		{
			dfs(next);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int>trust;
	int N, M, T, ans = 0;

	cin >> N >> M >> T;

	if (T != 0)
	{
		for (int i = 0; i < T; i++)
		{
			int u;
			cin >> u;

			trust.push_back(u);
		}
	}

		for (int i = 0; i < M; i++)
		{
			int n = 0, prev = 0;
			cin >> n;

			for (int j = 0; j < n; j++)
			{
				int h;
				cin >> h;
				input[i].push_back(h);

				if (j == 0)
				{
					prev = h;
				}
				else
				{
					link[prev].push_back(h);
					link[h].push_back(prev);
					prev = h;
				}
			}
		}

		if (T != 0)
		{
			for (int val : trust)
			{
				fill(visited, visited + 51, false);
				dfs(val);
			}

			for (int i = 0; i < M; i++)
			{
				ans++;
				for (int val : input[i])
				{
					if (v_trust[val])
					{
						ans--;
						break;
					}
				}
			}

			cout << ans;
		}
		else
		{
			cout << M;
		}
}