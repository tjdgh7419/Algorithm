#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long f, s, t = 0;
	vector<long long>vec;
	while (1)
	{
		vec.clear();

		cin >> f;
		vec.push_back(f);
		cin >> s;
		vec.push_back(s);
		cin >> t;
		vec.push_back(t);

		if (f == 0 && s == 0 && t == 0)
		{
			break;
		}

		sort(vec.begin(), vec.end());

		if (vec[2] * vec[2] == (vec[0] * vec[0]) + (vec[1] * vec[1]))
		{
			cout << "right" << '\n';
		}
		else
		{
			cout << "wrong" << '\n';
		}
	}
}