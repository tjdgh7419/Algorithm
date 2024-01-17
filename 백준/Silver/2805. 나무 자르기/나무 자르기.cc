#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<int> tree;
	int n, m, res = 0;
	int MIN = 0;
	int MAX = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;
		tree.push_back(height);
		if (MAX < tree[i]) MAX = tree[i];
	}

	while (MIN <= MAX)
	{
		long long wood = 0;
		int height = (MIN + MAX) / 2;

		for (int i = 0; i < n; i++)
		{
			if (tree[i] - height > 0) 
			{
				wood += tree[i] - height;
			}
		}

		if (wood >= m)
		{
			MIN = height + 1;
			res = max(res, height);
		}
		else
		{
			MAX = height - 1;
		}
	}
	cout << res;
}