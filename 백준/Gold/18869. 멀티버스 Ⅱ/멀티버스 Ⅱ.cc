#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>

using namespace std;

vector<vector<int>> M(101, vector<int>(0));

void Compression(vector<int>& v)
{
	vector<int> comp_arr = v;
	sort(comp_arr.begin(), comp_arr.end());
	comp_arr.erase(unique(comp_arr.begin(), comp_arr.end()), comp_arr.end());
	
	for (int i = 0; i < v.size(); i++)
	{
		int idx = lower_bound(comp_arr.begin(), comp_arr.end(), v[i]) - comp_arr.begin();
		v[i] = idx;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int m, n, ans = 0;

	cin >> m >> n;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int size;
			cin >> size;
			M[i].push_back(size);
		}
		Compression(M[i]);
	}
	
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			if (M[i].size() == M[j].size())
			{
				bool equal_chk = true;

				for (int k = 0; k < M[i].size(); k++)
				{
					if (M[i][k] != M[j][k])
					{
						equal_chk = false;
						break;
					}
				}

				if (equal_chk) ans++;
			}
		}
	}

	cout << ans;
}