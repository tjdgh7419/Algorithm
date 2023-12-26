#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>


using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<long long> vec;
	long long n, m, res = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		sort(vec.begin(), vec.end());
		long long sum = vec[0] + vec[1];
		vec[0] = sum;
		vec[1] = sum;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		res += vec[i];
	}

	cout << res;
}
