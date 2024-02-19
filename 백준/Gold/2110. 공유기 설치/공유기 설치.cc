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

int house[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, C, ans = 0;

	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}

	sort(house, house + N);

	int start = 1;
	int end = house[N - 1] - house[0];

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int prev = house[0];
		int set = 1;

		for (int i = 1; i < N; i++)
		{
			if (house[i] - prev >= mid)
			{
				set++;
				prev = house[i];
			}
		}

		if (set >= C)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans;
}