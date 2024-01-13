#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int dp[41] = {0, 1, };
int fibonacci(int N) {
    if (N == 0 || N == 1)
    {
        return dp[N];
    }
    else if(dp[N] == 0)
    {
        dp[N] = fibonacci(N - 1) + fibonacci(N - 2);
    }

    return dp[N];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int t, n = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        
        if (n == 0)
        {
            cout << 1 << ' ' << 0 << '\n';
            continue;
        }
       
        cout << fibonacci(n - 1) << ' ' << fibonacci(n) << '\n';
    }
}