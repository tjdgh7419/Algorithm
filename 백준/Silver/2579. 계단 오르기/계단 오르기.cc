#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int score[301];
int dp[301];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> score[i];
	}

	dp[1] = score[1];
	dp[2] = score[1] + score[2];
	dp[3] = max(score[1] + score[3], score[2] + score[3]);

	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + score[i], dp[i - 3] + score[i - 1] + score[i]);
	}

	cout << dp[n];
}