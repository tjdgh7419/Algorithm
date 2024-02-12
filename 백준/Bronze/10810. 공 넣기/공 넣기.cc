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

	int N, a;
	cin >> N >> a;
	 
	for (int i = 0; i < a; i++)
	{
		int f, s, t;
		cin >> f >> s >> t;

		fill((arr + f) - 1, arr + s, t);
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}