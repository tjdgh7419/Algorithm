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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int X, N, a, b, sum = 0;

	cin >> X >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		sum += a * b;
	}

	if (sum == X) cout << "Yes";
	else cout << "No";
}