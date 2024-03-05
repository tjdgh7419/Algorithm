#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <map>

using namespace std;

bool deci[4000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	vector<int>deci_val;

	deci[0] = deci[1] = true;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (!deci[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				deci[j] = true;
			}
		}		
	}

	for (int i = 0; i <= N; i++) 
	{
		if (!deci[i])
		{
			deci_val.push_back(i);
		}		
	}

	int start = 0, end = 0, sum = 0, ans = 0;

	while (start <= end)
	{
		if (sum >= N)
		{
			if (sum == N) ans++;

			sum -= deci_val[start++];
		}
		else if(end == deci_val.size())
		{
			break;
		}
		else
		{
			sum += deci_val[end++];
		}
	}

	cout << ans;
}