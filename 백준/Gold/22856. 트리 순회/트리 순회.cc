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
vector<pair<int, int>> parent(100001);

int right_node = -1;

void inorder(int node, bool flag)
{
	if (node == -1) return;

	int left = parent[node].first;
	int right = parent[node].second;

	inorder(left, 0);

	if (flag == 1)
	{
		right_node++;
		inorder(right, 1);
	}
	else
	{
		inorder(right, 0);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int p, l, r;
		cin >> p >> l >> r;

		parent[p].first = l;
		parent[p].second = r;
	}

	inorder(1, 1);
	cout << ((N - 1) * 2) - right_node;
}


