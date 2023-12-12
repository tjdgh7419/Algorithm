#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	int m = 0;
	int nVal = 0;
	
	int arr[500002];
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nVal;
		arr[i] = nVal;
	}

	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> nVal;
		cout << upper_bound(arr, arr + n, nVal) - lower_bound(arr, arr + n, nVal) << " ";
	}		
}