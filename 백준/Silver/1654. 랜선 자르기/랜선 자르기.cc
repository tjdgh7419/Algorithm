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
	long start = 1;
	long end = 0;
	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		cin >> lan[i];
		end = max(end, lan[i]);
	}

	sort(lan, lan + k);


	while (start <= end)
	{
		long sum = 0;
		long mid = (start + end) / 2;

		for (int i = 0; i < k; i++)
		{
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