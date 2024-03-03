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


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	while (true)
	{
		int a, b;

		cin >> a >> b;

		if (a == 0 && b == 0) break;

		cout << (a > b ? "Yes" : "No") << "\n";
	}
}