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
int square[1002][1002];
int dp[1002][1002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, MAX_length = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string num;
		cin >> num;

		for (int j = 1; j <= m; j++)
		{
			square[i][j] = num[j - 1] - '0';
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (square[i][j] == 1) 
			{
				dp[i][j] = min({ dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j] }) + 1;
				MAX_length = max(MAX_length, dp[i][j]);
			}
		}
	}

	cout << MAX_length * MAX_length;
}