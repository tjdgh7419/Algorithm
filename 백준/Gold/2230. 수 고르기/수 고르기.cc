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

	int N, M;
	int ans = 0x7fffffff;
	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int end = 0;

	for (int start = 0; start < N; start++)
	{
		while (end < N && arr[end] - arr[start] < M) end++;
		if (end == N) break;
		ans = min(ans, arr[end] - arr[start]);
	}

	cout << ans;
}