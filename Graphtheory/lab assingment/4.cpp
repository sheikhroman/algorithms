#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
vector<int> adj_list[N];
int visited[N];
int countcycle = 0;
int sp, ep;
vector<int> cycle;
vector<int> parent;
stack<int> recursionStack;
vector<bool> rsFlag;

bool detect_cycle(int node){

    visited[node] = 1;
    recursionStack.push(node);
    rsFlag[node] = true;

    for (auto adj_node : adj_list[node]){
        if (visited[adj_node] == 0){
            bool got_cycle = detect_cycle(adj_node);
            if (got_cycle){
                return true;
            }
        }
        else if (visited[adj_node] == 1){
            recursionStack.push(adj_node);
            return true;
        }
    }
    recursionStack.pop();
    rsFlag[node] = false;
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
            bool got_cycle = detect_cycle(i);
            if (got_cycle){
                cycle_exists = true;
                break;
            }
        }
    }
    if (recursionStack.empty()){
        cout << "Impossible" << endl;
        return 0;
    }
}
