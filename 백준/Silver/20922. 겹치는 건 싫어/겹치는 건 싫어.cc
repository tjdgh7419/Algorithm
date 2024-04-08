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

int arr[200001];
int visited[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K, end = 0, start = 0, len = 0, ans = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	while (end < N)
	{
		if (visited[arr[end]] < K)
		{
			visited[arr[end]]++;
			end++;
			len++;

			ans = max(ans, len);
		}
		else
		{
			visited[arr[start]]--;
			len--;
			start++;
		}
	}

	cout << ans;
}