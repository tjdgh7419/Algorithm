#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>


using namespace std;

int t_list[1001];
int dp[31][2][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, w, res = 0;
	cin >> t >> w;

	for (int i = 1; i <= t; i++)
	{
		cin >> t_list[i];
	}

	for (int i = 0; i <= w; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			if (i == 0)
			{
				dp[i][0][j] = dp[i][0][j - 1] + (t_list[j] == 1);
			}
			else
			{
				dp[i][0][j] = max(dp[i][0][j - 1] + (t_list[j] == 1), dp[i - 1][1][j - 1] + (t_list[j] == 1));

				dp[i][1][j] = max(dp[i][1][j - 1] + (t_list[j] == 2), dp[i - 1][0][j - 1] + (t_list[j] == 2));
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			res = max(dp[j][i][t], res);
		}
	}
	cout << res;
}