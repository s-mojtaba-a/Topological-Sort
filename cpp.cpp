#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void topo_sort(vector<int> &topo, int n, vector<vector<int>> &s)
{
    /* n = number of vertices
    topo contains sorted vertices
    s = adjacency list of graph 
    */
    int in_degree[n + 1] = {0};
    in_degree[0] = 100000000;
    topo.reserve(n);
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 1; i <= n; i++)
    {
        for (int j : s[i])
        {
            in_degree[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
            Q.push(i);
    }
    while (!Q.empty())
    {
        int v = Q.top();
        Q.pop();
        topo.emplace_back(v);
        for (int i : s[v])
        {
            in_degree[i]--;
            if (!in_degree[i])
            {
                Q.push(i);
            }
        }
    }
}
int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a].emplace_back(b);
    }
    vector<int> topo;
    topo_sort(topo, n, s);
    for (int i : topo)
        cout << i << " ";
    */
}
