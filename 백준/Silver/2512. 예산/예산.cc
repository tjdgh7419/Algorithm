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

int M[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, budget, ans = 0;
	int start = 0;
	int end = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M[i];
		if (end < M[i]) end = M[i];
	}

	cin >> budget;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		long sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (M[i] > mid)
			{
				sum += mid;
			}
			else
			{
				sum += M[i];
			}
		}

		if (sum <= budget)
		{
			start = mid + 1;
			ans = mid;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << ans;
}