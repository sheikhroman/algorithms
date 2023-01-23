#include <bits/stdc++.h>
using namespace std;

int main(){

    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
    int dgraph[n][m] = {};

    for (int i = 0; i < m; i++)
    { // loop over the number of edges
        int u, v;
        cin >> u >> v; // There exists a directed edge from u to v
        dgraph[u][v] = 1;
    }

    int trimedge = 0;
        for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dgraph[i][j] != dgraph[j][i]){
                trimedge++;
            }
        }
    }

    cout << endl;
    cout << "We have to remove " << trimedge / 2 << " edge to make this graph bidirectional" << endl;

    return 0;
}
