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

int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, fir, sec;
	int prev_liq = INT_MAX;

	cin >> N;

	int start = 0;
	int end = N - 1;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (start < end)
	{
		int liq = arr[start] + arr[end];

		if (abs(liq) < prev_liq)
		{
			fir = arr[start];
			sec = arr[end];
			prev_liq = abs(liq);
		}

		if (liq < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << fir << " " << sec;
}