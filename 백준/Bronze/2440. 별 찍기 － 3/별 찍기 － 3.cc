#include<iostream>
#include<algorithm>
#include<string>

using namespace std;


int main()
{
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << "*";
		}
		cout << '\n';
	}
}