#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int n, res = 0;
pair<int, int> arr[9];

void DFS(int nEgg)
{
	if (nEgg == n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].first <= 0) cnt++;			
		}
		res = max(res, cnt);
		return;
	}

	if (arr[nEgg].first <= 0)
	{
		DFS(nEgg + 1);
		return;
	}

	bool isCracked = false;
	for (int i = 0; i < n; i++)
	{
		if (i == nEgg || arr[i].first <= 0) continue;

		isCracked = true;
		arr[nEgg].first -= arr[i].second;
		arr[i].first -= arr[nEgg].second;
		DFS(nEgg + 1);
		arr[nEgg].first += arr[i].second;
		arr[i].first += arr[nEgg].second;
	}

	if (!isCracked) DFS(nEgg + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	DFS(0);

	cout << res;
}