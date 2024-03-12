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

vector<vector<int>> link(100001);
bool visited[100001];
int subtree[100001];

int dfs(int root)
{
	if (subtree[root] != 0) return subtree[root];
	visited[root] = true;
	int sub = 1;

	for (int i = 0; i < link[root].size(); i++)
	{
		int next = link[root][i];
		if (!visited[next])
		{
			sub += dfs(next);
		}
	}
	subtree[root] = sub;
	return sub;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, R, Q;

	cin >> N >> R >> Q;

	for (int i = 0; i < N - 1; i++)
	{
		int U, V;
		cin >> U >> V;

		link[U].push_back(V);
		link[V].push_back(U);
	}

	subtree[R] = dfs(R);

	for (int i = 0; i < Q; i++)
	{
		int n;
		cin >> n;

		cout << subtree[n] << '\n';
	}
}




