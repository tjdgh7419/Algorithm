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

int code_arr[5001];
int dp[5001];
#define MOD 1000000
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string code;
	cin >> code;

	for (int i = 1; i <= code.length(); i++)
	{
		code_arr[i] = code[i - 1] - '0';
	}

	if (code_arr[1] == 0)
	{
		cout << 0;
		return 0;
	}

	dp[0] = 1;

	for (int i = 1; i <= code.length(); i++)
	{
		if (code_arr[i] >= 1 && code_arr[i] <= 9)
		{
			dp[i] = (dp[i - 1] + dp[i]) % MOD;
		}

		if (i == 1) continue;
		int tmp = (code_arr[i - 1] * 10) + code_arr[i];

		if (tmp >= 10 && tmp <= 26)
		{
			dp[i] = (dp[i - 2] + dp[i]) % MOD;
		}

	}

	cout << dp[code.length()];
}