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
int arr[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> sum;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			sum.push_back(arr[i] + arr[j]);
		}
	}

	sort(arr, arr + N);
	sort(begin(sum), end(sum));

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			int search_val = arr[i] - arr[j];
			bool exist = binary_search(begin(sum), end(sum), search_val);

			if (exist)
			{
				cout << arr[i];
				return 0;
			}
		}
	}
}