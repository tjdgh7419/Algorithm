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

	int N, M, f, s;

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> f >> s;
		int tmp;

		tmp = arr[f];
		arr[f] = arr[s];
		arr[s] = tmp;
	}

	for (int i = 1; i <= N; i++)
	{
		cout << arr[i] << " ";
	}
}