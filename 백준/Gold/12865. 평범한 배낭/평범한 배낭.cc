#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int bag[101][100001];
int n, k = 0;
vector<pair<int, int>> item;

void dp() 
{
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i < item[j].first)
			{
				bag[j][i] = bag[j - 1][i];
			}
			else
			{
				bag[j][i] = max(bag[j - 1][i - item[j].first] + item[j].second, bag[j - 1][i]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	item.push_back({0, 0});
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		item.push_back({w, v});
	}
	
	dp();

	cout << bag[n][k];
}