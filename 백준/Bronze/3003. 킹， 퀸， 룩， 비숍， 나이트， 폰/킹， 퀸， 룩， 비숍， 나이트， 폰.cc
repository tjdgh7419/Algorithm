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


int arr[6] = { 1, 1, 2, 2, 2, 8 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i < 6; i++)
	{
		int a;
		cin >> a;

		if (arr[i] == a)
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = arr[i] - a;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		cout << arr[i] << " ";
	}
}