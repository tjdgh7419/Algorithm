#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;
long long tri[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t = 0;
	
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		
		tri[1] = 1;
		tri[2] = 1;
		tri[3] = 1;
		tri[4] = 2;
		tri[5] = 2;

		if (n < 6)
		{
			cout << tri[n] << '\n';
			continue;
		}

		if (tri[n] == 0) 
		{
			for (int j = 6; j <= n; j++)
			{
				tri[j] = tri[j - 5] + tri[j - 1];
			}

			cout << tri[n] << '\n';
			continue;
		}
		else
		{
			cout << tri[n] << '\n';
			continue;
		}
	}
}