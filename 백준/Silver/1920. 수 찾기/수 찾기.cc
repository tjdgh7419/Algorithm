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

int arr[100001];
int num[100001];

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
		int start = 0;
		int end = n - 1;

		while (true)
		{
			if (start > end)
			{
				cout << "0" << '\n';
				break;
			}

			int mid = (start + end) / 2;

			if (arr[mid] == num[i])
			{
				cout << "1" << '\n';
				break;
			}		
			else if (num[i] > arr[mid])
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}			
		}
	}
}