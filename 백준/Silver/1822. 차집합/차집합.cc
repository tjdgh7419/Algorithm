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

int arr1[500001];
int arr2[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, ans = 0;
	vector<int>vec;
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		cin >> arr1[i];
	}

	for (int i = 0; i < b; i++)
	{
		cin >> arr2[i];
	}

	sort(arr2, arr2 + b);

	for (int i = 0; i < a; i++)
	{
		bool exist = binary_search(arr2, arr2 + b, arr1[i]);

		if (!exist)
		{
			ans++;
			vec.push_back(arr1[i]);
		}
	}

	cout << ans << '\n';

	sort(vec.begin(), vec.end());
	if (vec.size() != 0) 
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
	}
}