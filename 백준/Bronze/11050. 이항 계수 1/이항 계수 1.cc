#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
int dp[11];
int factorial(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	
	if (dp[n] != 0)
	{
		return dp[n];
	}
	else
	{
		dp[n] = factorial(n - 1) * n;
		return dp[n];
	}
}
int main()
{
	int N, M, res = 0;

	cin >> N >> M;
	if ((factorial(N - M) * factorial(M)) != 0)
	{
		res = factorial(N) / (factorial(N - M) * factorial(M));
	}
	else
	{
		res = 1;
	}
	cout << res;
}