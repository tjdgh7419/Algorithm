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

int ver[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin >> start >> end;
		
		for (int j = start; j < end; j++)
		{
			ver[j]++;
		}
	}

	int start = 0, end = 0, ans = 0;

	while (start <= end && end <= 1000000)
	{
		if (ans == K)
		{
			cout << start << " " << end;
			return 0;
		}
		else if (ans < K) 
		{
			ans += ver[end++];
		}
		else 
		{
			ans -= ver[start++];
		}
	}

	cout << "0" << " " << "0";
}