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

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, S;
	int ans = INT_MAX;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = 0, end = 0, sum = 0;

	while (start <= end)
	{
		if (sum >= S)
		{
			ans = min(ans, end - start);
			sum -= arr[start++];
		}
		else if (end == N) break;
		else sum += arr[end++];
	}

	if (ans == INT_MAX) cout << "0";
	else cout << ans;
}