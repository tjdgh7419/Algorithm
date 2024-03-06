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

int arr[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = 0, sum = 0, ans = 0;

	while (start <= end)
	{
		if (sum >= M)
		{
			if (sum == M) ans++;
			sum -= arr[start++];
		}
		else if (end == N)
		{
			break;
		}
		else
		{
			sum += arr[end++];
		}
	}

	cout << ans;
}