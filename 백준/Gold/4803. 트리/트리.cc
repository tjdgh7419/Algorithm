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

int visted[501];

bool bfs(vector<vector<int>> linkvec, int start)
{
	queue<int> q;
	q.push(start);
	visted[start] = 1;

	bool tree = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto next : linkvec[cur])
		{
			if (visted[next] != 0 && visted[next] != visted[cur] - 1)
			{
				tree = false;
			}

			if (visted[next] != 0) continue;
				visted[next] = visted[cur] + 1;
				q.push(next);
		}
	}
	return tree;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c = 1;

	while (true)
	{
		int n, m; 
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		vector<vector<int>> linkvec(n + 1);

		for (int i = 0; i < m; i++)
		{
			int f, s;
			cin >> f >> s;

			linkvec[f].push_back(s);
			linkvec[s].push_back(f);
		}

		fill(visted, visted + 501, 0);

		int ans = 0;

		for (int start = 1; start <= n; start++)
		{
			if (visted[start] == 0)
			{
				if (bfs(linkvec, start)) ans++;
			}
		}

		cout << "Case " << c++ << ": ";
		if (ans > 1) cout << "A forest of " << ans << " trees.";
		else if (ans == 1) cout << "There is one tree.";
		else cout << "No trees.";
		cout << '\n';
	}
}
