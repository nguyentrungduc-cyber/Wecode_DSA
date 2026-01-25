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

    // BFS
    queue<int> q;
    vector<bool> visited(m, false);
    bool found = false;
    q.push(0);
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
                // cout << v << " ";
                q.push(v);
                found = true;
            }
        }
    }

    // In kết quả
    if (!found)
    {
        cout << "KHONG";
    }
    else
    {
        for (int i = 1; i < m; i++)
        {
            if (visited[i])
            {
                cout << i << " ";
            }
        }
    }

    return 0;
}