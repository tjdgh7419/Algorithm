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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, L, ans = 1001;
	cin >> N >> M >> L;

	vector<int>location;

	location.push_back(0);
	location.push_back(L);

	for (int i = 0; i < N; i++)
	{
		int info;
		cin >> info;
		location.push_back(info);
	}

	sort(location.begin(), location.end());

	int start = 1;
	int end = L - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;

		for (int i = 1; i < location.size(); i++)
		{
			int dist = location[i] - location[i - 1];
			int cnt = dist / mid;

			if (dist % mid == 0)
			{
				cnt -= 1;
			}

			sum += cnt;
		}

		if (sum > M)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
			ans = min(ans, mid);
		}
	}

	cout << ans;
}