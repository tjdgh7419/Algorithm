#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int arr[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << arr[end] - arr[start - 1] << '\n';
	}
}