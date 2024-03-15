#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> parent[51];
bool visited[51];
int target, ans = 0;

void dfs(int start) {
    if (visited[start]) return;
 
    visited[start] = true;

    if (!parent[start].size() || (parent[start].size() == 1 && parent[start][0] == target)) 
    {
        ans++;
        return;
    }

    for (int i = 0; i < parent[start].size(); i++) {
        if (!visited[parent[start][i]]) {
            dfs(parent[start][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, root;
    cin >> N;

    for (int i = 0; i < N; i++) {

        int p_node;
        cin >> p_node;

        if (p_node == -1) 
        {
            root = i;
        }
        else
        {
            parent[p_node].push_back(i);
        }
    }

    cin >> target;
    visited[target] = true;
    dfs(root);

    cout << ans;
}
