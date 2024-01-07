#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>

using namespace std;
int lcs[1001][1001];
int arr1[1001];
int arr2[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string str1, str2;
	int res = 0;
	cin >> str1 >> str2;

	for (int i = 1; i <= str1.size(); i++)
	{
		arr1[i] = str1[i - 1];
	}
	for (int j = 1; j <= str2.size(); j++)
	{
		arr2[j] = str2[j - 1];
	}

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (i == 0 || j == 0)
			{
				lcs[i][j] = 0;
			}
			else if (arr1[i] == arr2[j])
			{
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else
			{
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			res = max(res, lcs[i][j]);
		}
	}

	cout << res;
}









