#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n; // m: dinh, n: canh

    // Tạo danh sách kề cho đồ thị
    vector<vector<int>> adj(m);

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Vô hướng: thêm cả hai chiều
    }

    int dinhcolap[m] = {};
    // BFS
    for (int i = 0; i < m; i++)
    {
        queue<int> q;
        vector<bool> visited(m, false);
        q.push(i);
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            visited[c] = true;
            for (int v : adj[c])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    dinhcolap[i]++;
                    // cout << v << " ";
                    q.push(v);
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (dinhcolap[i] == 0)
        {
            sum++;
        }
    }
    cout << sum;

    return 0;
}