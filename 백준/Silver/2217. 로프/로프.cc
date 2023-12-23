#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	int a = 0;
	int max = 0;
	int sum = 0;
	cin >> n;
	vector<int>vec;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end(), [](int a, int b) {return a > b; });

	for (int i = 0; i < vec.size(); i++)
	{
		int weight = vec[i] * (i + 1);

		if (max < weight)
		{
			max = weight;
		}
	}

	cout << max;
}