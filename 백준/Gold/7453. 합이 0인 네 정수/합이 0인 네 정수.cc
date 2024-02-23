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

int A[4001];
int B[4001];
int C[4001];
int D[4001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	long long ans = 0;

	cin >> n;

	vector<int>left_val;
	vector<int>right_val;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
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
	sort(left_val.begin(), left_val.end());
	sort(right_val.begin(), right_val.end());

	for (int i = 0; i < left_val.size(); i++)
	{
		int upper = upper_bound(right_val.begin(), right_val.end(), -left_val[i]) - right_val.begin();
		int lower = lower_bound(right_val.begin(), right_val.end(), -left_val[i]) - right_val.begin();

		ans += (upper - lower);
	}

	cout << ans;
}
