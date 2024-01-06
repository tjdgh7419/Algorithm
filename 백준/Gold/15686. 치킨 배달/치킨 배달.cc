#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

int arr[51][51];
int n, m = 0;
int res = 999999;
vector<pair<int, int>> peo;
vector<pair<int, int>> chi;
vector<int> sel;

void get_val()
{
	int g_res = 0;
	for (int i = 0; i < peo.size(); i++)
	{
		int mindis = 999999;
		int dis = 0;
		for (int j = 0; j < sel.size(); j++)
		{
			dis = abs(peo[i].first - chi[sel[j]].first) + abs(peo[i].second - chi[sel[j]].second);
			mindis = min(mindis, dis);
		}
		g_res += mindis;
	}
	res = min(res, g_res);
}

void select_m(int start, int cnt)
{
	if (cnt == m)
	{
		get_val();
	}

	for (int i = start; i < chi.size(); i++)
	{
		sel.push_back(i);
		select_m(i + 1, cnt + 1);
		sel.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				peo.push_back({i, j});
			}
			if (arr[i][j] == 2)
			{
				chi.push_back({i, j});
			}
		}
	}
	select_m(0, 0);
	
	cout << res;
}
