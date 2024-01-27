#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
int fibo[2000001];
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	int nChk = 0;
	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;


	if (n < 0)
	{
		if (n % 2 == 0)
		{
			nChk = -1;
		}
		else
		{
			nChk = 1;
		}
	}
	else if (n > 0) nChk = 1;
	else nChk = 0;

	if (n == 1) 
	{
		cout << nChk << '\n' << fibo[1];
		return 0;
	}
	else if (n == 0) 
	{
		cout << nChk << '\n' << fibo[0];
		return 0;
	}
	else if (n == -1)
	{
		cout << nChk << '\n' << fibo[1];
		return 0;
	}

	n = abs(n);

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = (fibo[i - 2] + fibo[i - 1]) % 1000000000;
	}

	cout << nChk << '\n' << fibo[n];
}