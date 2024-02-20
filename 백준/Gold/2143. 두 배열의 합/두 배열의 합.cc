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

	int T, n, m;
	long long ans = 0;

	cin >> T >> n;

	vector<int>n_vec(n);
	
	for (int i = 0; i < n; i++)
	{
		cin >> n_vec[i];
	}

	cin >> m;

	vector<int>m_vec(m);

	for (int i = 0; i < m; i++)
	{
		cin >> m_vec[i];
	}

	vector<long long>n_sum, m_sum;

	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += n_vec[j];
			n_sum.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		long long sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += m_vec[j];
			m_sum.push_back(sum);
		}
	}

	sort(m_sum.begin(), m_sum.end());

	for (int i = 0; i < n_sum.size(); i++)
	{
		int target = T - n_sum[i];
		
		auto lower = lower_bound(m_sum.begin(), m_sum.end(), target);
		auto upper = upper_bound(m_sum.begin(), m_sum.end(), target);
		ans += (upper - lower);
	}

	cout << ans;
}




