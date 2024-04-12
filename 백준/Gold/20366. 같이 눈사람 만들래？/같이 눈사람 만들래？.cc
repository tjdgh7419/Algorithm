#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <map>

using namespace std;

int snow[601];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, ans = INT_MAX;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> snow[i];
	}

	sort(snow, snow + N);

	for (int i = 0; i < N - 3; ++i)
	{
		for (int j = i + 3; j < N; ++j)
		{
			int start = i + 1, end = j - 1, elsa = snow[i] + snow[j];

			while (start < end)
			{
				int anna = snow[start] + snow[end];
				int res = elsa - anna;
				ans = min(ans, abs(res));

				if (res > 0) start++;
				else if (res < 0) end--;
				else
				{
					cout << "0";
					return 0;
				}
			}
		}
	}

	cout << ans;
}