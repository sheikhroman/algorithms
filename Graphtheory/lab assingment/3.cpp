#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int visted[N];
vector<int> adj_list[N];
bool iscycle = false;
int cycles = 0;

void bfs(int src){

    queue<int> q;
    q.push(src);
    visted[src] = 1;
    while (!q.empty()){
        int head = q.front();
        q.pop();
        for (int adj_node : adj_list[head]){
            if (visted[adj_node] == 0){
                visted[adj_node] = 1;
                q.push(adj_node);
            }
            if (visted[adj_node] == 1){
                iscycle = true;
            }
        }
    }
}

int main(){
    int node, edges;
    cin >> node >> edges;
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }
    bfs(0);
    if (iscycle){
        cout << "There is cycle exist" << endl;
    }
    else{
        cout << "There is no cycle!! " << endl;
    }
    return 0;
}

/* sample test
 5 6
 0 1
 1 2
 2 4
 4 2
 2 3
 3 0
*/