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

int num_arr[2001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num_arr[i];
	}

	sort(num_arr, num_arr + N);

	for (int i = 0; i < N; i++)
	{
		int start = 0;
		int end = N - 1;

		while (start < end)
		{
			if (start == i)
			{
				start++;
				continue;
			}

			if (end == i)
			{
				end--;
				continue;
			}

			if (num_arr[i] == num_arr[start] + num_arr[end])
			{
				ans++;
				break;
			}

			if (num_arr[i] > num_arr[start] + num_arr[end])
			{
				start++;
			}
			else
			{
				end--;
			}
		}
	}

	cout << ans;
}