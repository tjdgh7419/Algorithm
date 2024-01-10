#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int arr[100001];
int dp[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << dp[end] - dp[start - 1] << '\n';
	}
}