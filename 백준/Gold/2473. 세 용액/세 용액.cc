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

long long liq[5001];
long long ans[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	long long equ_val = LLONG_MAX;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> liq[i];
	}

	sort(liq, liq + N);

	for (int i = 0; i < N - 1; i++)
	{
		int start = i + 1;
		int end = N - 1;

		while (start < end)
		{
			long long comp_liq = liq[start] + liq[end] + liq[i];

			if (abs(comp_liq) < equ_val)
			{
				equ_val = abs(comp_liq);
				ans[0] = liq[i];
				ans[1] = liq[start];
				ans[2] = liq[end];
			}

			if (comp_liq < 0) start++;
			else end--;
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];
}


