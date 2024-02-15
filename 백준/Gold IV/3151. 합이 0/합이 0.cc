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

int coding_skill[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	long ans = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> coding_skill[i];
	}

	sort(coding_skill, coding_skill + N);

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			long sum = coding_skill[i] + coding_skill[j];

			int start = lower_bound(coding_skill + j + 1, coding_skill + N, -sum) - coding_skill;
			int end = upper_bound(coding_skill + j + 1, coding_skill + N, -sum) - coding_skill;

			ans += end - start;
		}
	}

	cout << ans;
}