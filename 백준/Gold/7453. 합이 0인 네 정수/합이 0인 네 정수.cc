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

long long A[4001];
long long B[4001];
long long C[4001];
long long D[4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n;
	long long ans = 0;

	cin >> n;

	vector<long long>left_val;
	vector<long long>right_val;

	for (int i = 0; i < n; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;

		A[i] = a;
		B[i] = b;
		C[i] = c;
		D[i] = d;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			left_val.push_back(A[i] + B[j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			right_val.push_back(C[i] + D[j]);
		}
	}

	sort(right_val.begin(), right_val.end());

	for (int i = 0; i < left_val.size(); i++)
	{
		auto upper = upper_bound(right_val.begin(), right_val.end(), -left_val[i]);
		auto lower = lower_bound(right_val.begin(), right_val.end(), -left_val[i]);

		ans += (upper - lower);
	}

	cout << ans;
}