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

int sequence[2001];
int palindrom[2001][2001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, t = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
		palindrom[i][i] = 1;

		if (i != 1 && sequence[i] == sequence[i - 1])
		{
			palindrom[i - 1][i] = 1;
		}
	}

	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 1; i + j <= n; j++)
		{
			if (sequence[j] == sequence[i + j] && palindrom[j + 1][i + j - 1] == 1)
			{
				palindrom[j][i + j] = 1;
			}
		}
	}

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int start, end;

		cin >> start >> end;

		cout << palindrom[start][end] << '\n';
	}
}




