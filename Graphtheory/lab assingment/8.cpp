#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e7;
int visited[N];
vector<int> adj_list[N];
vector<int> bridges;
void dfs(int src){
    visited[src] = 1;
    for (int adj_node : adj_list[src]){
        if (visited[adj_node] == 0)
        {
            dfs(adj_node);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 1; i <= n; i++){
        if (visited[i] == 0){
            bridges.push_back(i);
            dfs(i);
        }
    }
    long long int lenghtvec = bridges.size() - 1;
    cout << lenghtvec << endl;
    for (long long int i = 0; i < lenghtvec; i++){
        cout << bridges[i] << " " << bridges[i + 1] << endl;
    }

    return 0;
}