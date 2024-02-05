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
long lan[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long k, n, ans = 0;

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> lan[i];
	}

	sort(lan, lan + k);

	long start = 0;
	long end = lan[k - 1];

	while (start <= end)
	{
		long sum = 0;
		long mid = (start + end) / 2;

		for (int i = 0; i < k; i++)
		{
			if (mid == 0)
			{
				sum = LONG_MAX;
				break;
			}
			sum += lan[i] / mid;
		}

		if (sum >= n)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << ans;
}