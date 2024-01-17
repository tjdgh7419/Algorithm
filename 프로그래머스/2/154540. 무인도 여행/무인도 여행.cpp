#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <string.h>
#include <limits.h>
using namespace std;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool visit[101][101];


int BFS(int x, int y, vector<string> map)
{
    queue<pair<int, int>>q;
    int res = 0;
    res += map[x][y] - '0';
    visit[x][y] = true;
    q.push({x, y});

    while (!q.empty())
    {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = qx + dx[i];
            int ny = qy + dy[i];

            if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[x].size()) continue;
            if (!visit[nx][ny] && map[nx][ny] != 'X')
            {
                visit[nx][ny] = true;
                q.push({nx, ny});
                res += map[nx][ny] - '0';
            }
        }
    }
    return res;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    bool bfs_chk = false;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'X' && !visit[i][j])
            {
                bfs_chk = true;
                answer.push_back(BFS(i, j, maps));
            }
        }
    }
    if (!bfs_chk)
    {
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}