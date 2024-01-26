#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

int dp[100001][3];
int graph[100001][3];
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	int test = 1;
	while (true) {

		cin >> n;
		if (n == 0) break;

		memset(graph, 0, sizeof(graph));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> graph[i][j];
			}
		}

		dp[0][0] = 1000001;
		dp[0][1] = graph[0][1];
		dp[0][2] = dp[0][1] + graph[0][2];

		for (int i = 1; i < n; i++)
		{
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][0];
			dp[i][1] = min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] }) + graph[i][1];
			dp[i][2] = min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] }) + graph[i][2];
		}

		cout << test << "." << " " << dp[n - 1][1] << '\n';
		test++;
	}
}