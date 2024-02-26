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

int A[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, ans = 0;
	vector<int>inc_seq;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	inc_seq.push_back(0);

	for (int i = 0; i < N; i++)
	{
		if (inc_seq.back() < A[i])
		{
			inc_seq.push_back(A[i]);
			ans++;
		}
		else 
		{
			int idx = lower_bound(inc_seq.begin(), inc_seq.end(), A[i]) - inc_seq.begin();
			inc_seq[idx] = A[i];
		}
	}

	cout << ans;
}