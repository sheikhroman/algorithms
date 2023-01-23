#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
vector<int> adj_list[N];

void dfs(int node){
    visited[node] = 1;
    for (int adj_node : adj_list[node])
    {
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
}

int main()
{
    int node, edges;
    cin >> node >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int components = 0;

    for (int i = 1; i <= node; i++){
        if (visited[i])
            continue;
        dfs(i);
        components++;
    }
    cout << "Number of components in graph is: " << components << endl;

    return 0;
}
// ==Test case
// 5 4
// 1 2
// 1 3
// 2 3
// 4 5
