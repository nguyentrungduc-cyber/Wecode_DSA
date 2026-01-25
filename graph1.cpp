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

    // BFS từ đỉnh 0
    // vector<bool> visited(m, false);
    // queue<int> q;
    // q.push(0);
    // visited[0] = true;
    // while (!q.empty())
    // {
    //     int u = q.front();
    //     q.pop();
    //     // Duyệt tất cả đỉnh kề với u
    //     for (int v : adj[u])
    //     {
    //         if (!visited[v])
    //         {
    //             visited[v] = true;
    //             q.push(v);
    //         }
    //     }
    // }

    // BFS
    queue<int> q;
    vector<bool> visited(m, false);
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
                q.push(v);
            }
        }
    }

    // In kết quả
    for (int i = 1; i < m; i++)
    {
        if (visited[i])
            cout << "CO\n";
        else
            cout << "KHONG\n";
    }

    return 0;
}