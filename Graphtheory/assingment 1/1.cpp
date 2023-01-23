#include <bits/stdc++.h>
using namespace std;
int main()
{
    // n = number of nodes
    // m = number of edges
    int n, m;
    cin >> n >> m;
    int dgraph[n][m] = {};

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        dgraph[u][v] = 1;
    }

    bool found = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dgraph[i][j] == 1 && dgraph[j][i] != 1){
                found = true;
                break;
            }
        }
    }

    cout << endl;
    if (found){
        cout << " it is not bi-directionoal " << endl;
    }else{
        cout << "It is  bi-directionoal " << endl;
    }
    return 0;
}

// 3 3
// 1 2
// 2 1
// 3 4

