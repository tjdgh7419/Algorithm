#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char cur;
	vector<char>vec;
	int rCnt = 0;
	int lCnt = 0;
	int sum = 0;
	char prev = ' ';
	while ((cur = getchar()) != '\n')
	{
		vec.push_back(cur);
	}

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		char comp = vec[i];

		if (prev == '(' && comp == '(')
		{		
			rCnt--;
			sum += 1;
			prev = comp;
		}

		else if (prev == ')' && comp == '(')
		{
			rCnt--;
			sum += rCnt;		
			prev = comp;
		}

		else {
			rCnt++;
			prev = comp;
		}

		vec.pop_back();
	}

	cout << sum;
}
