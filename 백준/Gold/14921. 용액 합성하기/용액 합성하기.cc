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

int liq[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> liq[i];
	}

	int start = 0;
	int end = N - 1;
	int MIN = INT_MAX;
	int ans = 0;
	while (start < end)
	{
		int mid = liq[start] + liq[end];

		if (abs(mid) < MIN)
		{
			MIN = abs(mid);
			ans = mid;
		}

		if (mid < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << ans;
}