#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

long long a, b, c, r = 0;

long long divide(long long b)
{
	if (b == 0) return 1;
	if (b == 1) return a % c;

	r = divide(b / 2) % c;

	if (b % 2 == 0) return r * r % c;
	return r * r % c * a % c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	cout << divide(b);
}