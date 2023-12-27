#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int>pn;
	vector<int>nn;

	int n = 0;
	int res = 0;
	int zCnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			zCnt++;
		}
		else if (num == 1)
		{
			res += 1;
		}
		else if (num > 1)
		{
			pn.push_back(num);
		}
		else
		{
			nn.push_back(num);
		}
	}

	if (pn.size() >= 1)
	{		
		sort(pn.begin(), pn.end(), greater<int>());
		int ptmp = 0;
		for (int i = 0; i < pn.size(); i++)
		{
			ptmp = pn[i];
			if (i % 2 == 1)
			{
				res += pn[i - 1] * pn[i];
				ptmp = 0;
			}
		}
		res += ptmp;
	}
	/*if (pn.size() == 1)
	{
		res += pn[0];*/

	if (nn.size() >= 1)
	{
		sort(nn.begin(), nn.end());
		int ntmp = 0;
		for (int i = 0; i < nn.size(); i++)
		{
			ntmp = nn[i];
			if (i % 2 == 1)
			{
				res += nn[i - 1] * nn[i];
				ntmp = 0;
			}
		}

		if (zCnt == 0)
		{
			res += ntmp;
		}
	}
	/*else if(nn.size() == 1)
	{
		if (zCnt > 0)
		{
			zCnt--;
		}
		else 
		{
			res += nn[0];
		}
	}*/


	cout << res;
}
