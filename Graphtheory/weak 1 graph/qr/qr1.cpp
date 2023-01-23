#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
const int INF = 1e9;
vector<pair<int, int>> g[MAX];   
vector<int> shortest_path_edges; 
int dist[MAX];                   
bool vis[MAX];                  
int n, m, source, target;

void dijkstra(int source){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto [v, w] : g[u]){
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                if (v == target)
                    shortest_path_edges.push_back(u);
            }
        }
    }
}

int main(){
    cin >> n >> m >> source >> target;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dijkstra(source);
    int shortest_distance = dist[target];
    cout << "Shortest distance: " << shortest_distance << endl;

    for (auto edge : shortest_path_edges){
        for (auto it = g[edge].begin(); it != g[edge].end();){
            if (it->first == target)
                g[edge].erase(it);
            else
                ++it;
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    dijkstra(source);
    int second_shortest_distance = dist[target];
    cout << "Second shortest distance: " << second_shortest_distance << endl;

    return 0;
}