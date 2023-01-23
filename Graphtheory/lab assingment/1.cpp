#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visited[N];
int levels[N];

vector<int> adj_list[N];

void dfs(int src, int parent = 0, int level = 0){
    levels[src] = level;
    visited[src] = 1;
    for (int adj_node : adj_list[src]){
        if (visited[adj_node] == 0){
            dfs(adj_node, src, level + 1);
        }
    }
}

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    int src;
    cout << "Enter the source"
         << " ";
    cin >> src;
    dfs(src);

    for (int i = 1; i <= nodes; i++){
        cout << "node " << i << "->level: " << levels[i] << endl;
    }
    return 0;
}
/*

test case
4 3
1 2
1 3
2 4

node 1->level: 0
node 2->level: 1
node 3->level: 1
node 4->level: 2
*/