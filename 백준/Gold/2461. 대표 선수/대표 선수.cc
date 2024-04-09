#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
#include <cstdio>
#include <map>

using namespace std;

vector<vector<int>> c_skill(1001);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ctor<vector<int>> c_skill;
	priority_queue<pair<int, pair<int, int>>> pq;

	int N, M, min_num = INT_MAX, result = INT_MAX;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int skill;
			cin >> skill;
			c_skill[i].push_back(skill);
		}
	}

	for (int i = 0; i < N; i++)
	{
		sort(c_skill[i].begin(), c_skill[i].end(), greater<int>());
		min_num = min(min_num, c_skill[i][0]);
		pq.push(make_pair(c_skill[i][0], make_pair(i, 0)));
	}

	while (!pq.empty())
	{
		int max_num = pq.top().first;
		int max_idx = pq.top().second.first;
		int max_arridx = pq.top().second.second;

		pq.pop();

		result = min(result, max_num - min_num);

		if (max_arridx + 1 == M) break;

		min_num = min(min_num, c_skill[max_idx][max_arridx + 1]);
		pq.push(make_pair(c_skill[max_idx][max_arridx + 1], make_pair(max_idx, max_arridx + 1)));
	}

	cout << result;
}