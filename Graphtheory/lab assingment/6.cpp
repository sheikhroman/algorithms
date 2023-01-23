#include <bits/stdc++.h>
using namespace std;

const long long int N = 1e7;
vector<int> adj_list[N];
int visited[N];
int indegrees[N];
long long int n, m;
vector<int> st;
bool bfs(int src){

    queue<int> q;
    for (int i = 1; i <= n; i++){
        for (auto degree : adj_list[i]){
            indegrees[degree]++;
        }
    }
    for (int i = 1; i <= n; i++){
        if (indegrees[i] == 0){
            q.push(i);
        }
    }
    while (!q.empty()){
        int head = q.front();
        visited[head] = 1;

        q.pop();
        st.push_back(head);
        for (int adj_node : adj_list[head]){
            indegrees[adj_node]--;
            if (indegrees[adj_node] == 0){
                q.push(adj_node);
            }
        }
    }
    if (st.size() == n){
        return true;
    }
    else{
        return false;
    }
}
int main(){

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
    }

    bool iscycle = false;

    for (int i = 1; i <= n; i++){
        if (visited[i] == 0){
            bool ans = bfs(i);
            if (!ans){
                iscycle = true;
                break;
            }
        }
    }

    if (iscycle){
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int nodes : st){
            cout << nodes << " ";
        }
    }

    return 0;
}