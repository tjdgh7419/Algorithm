#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int>vec;
	string m = "";
	int zCnt = 0;
	int nCnt = 0;
	bool zChk = false;
	bool nChk = false;

	cin >> m;

	for (int i = 0; i < m.length(); i++)
	{
		vec.push_back(m[i] - '0');
	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == 1 && !nChk)
		{
			nChk = true;
			zChk = false;
			nCnt++;
		}
		
		if (vec[i] == 0 && !zChk)
		{
			zChk = true;
			nChk = false;
			zCnt++;
		}
	}

	cout << min(nCnt, zCnt);
}