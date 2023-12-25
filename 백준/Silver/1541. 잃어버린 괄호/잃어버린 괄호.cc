#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>


using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input = "";
	string num = "";
	int res = 0;
	bool minus = false;
	cin >> input;

	for (int i = 0; i <= input.size(); i++)
	{
		if (input[i] == '+' || input[i] == '-' || i == input.size())
		{
			if (minus)
			{
				res -= stoi(num);
				num = "";
			}
			else if (input[i] == '-')
			{
				minus = true;
				res += stoi(num);
				num = "";
			}
			else
			{
				res += stoi(num);
				num = "";
			}
		}
		else
		{
			num += input[i];
		}
	}

	cout << res;
}