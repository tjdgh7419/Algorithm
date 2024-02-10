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
int arr[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, a, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cin >> a;

	for (int i = 0; i < N; i++)
	{
		if (a == arr[i])
		{
			cnt++;
		}
	}

	cout << cnt;
}