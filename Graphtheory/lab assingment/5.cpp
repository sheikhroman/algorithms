#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> adj_list[N];
int visited[N];
int parent[N];
int cycelscount = 0;
bool detect_cyclebfs(int node){
    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty()){
        int front = q.front();
        q.pop();
        for (auto adj_node : adj_list[front]){
            if (visited[adj_node] == true && adj_node != parent[front]){
                return true;
            }
            else if (visited[adj_node] == 0){
                q.push(adj_node);
                visited[adj_node] = 1;
                parent[adj_node] = front;
                cycelscount++;
            }
        }
    }
    return false;
}

int main(){

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v; // u -> v
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool cycle_exists = false;

    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            bool got_cycle = detect_cyclebfs(i);
            if (got_cycle){
                cycle_exists = true;
                break;
            }
        }
    }

    if (cycle_exists){
        cout << "Cycle Exists" << endl;
        cout << "No of node in the cycle " << cycelscount + 1 << endl;
    }
    else{
        cout << "Impossible No cycle" << endl;
    }
}

/*
test
5 6
1 3
1 2
5 3
1 5
2 4
4 5
*/