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

int arr[500001];
int num[500001];

void binary_search(int target, int start, int end)
{
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (arr[mid] == target)
		{
			cout << "1" << '\n';
			return;
		}
		else if (arr[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << "0" << '\n';
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num[i];
	}

	for (int i = 0; i < m; i++)
	{
		binary_search(num[i], 0, n - 1);
	}
}