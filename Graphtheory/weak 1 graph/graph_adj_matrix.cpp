/* 
Graph Representation

    Adjacency Matrix ->(2D Array)
    0-----1
        /  \
        2---3
   
   #total nodes = 4
   #total edge = 4
   #Undirected + Unweighted

   matrix -> #of nodes x #of nodes
          -> 4x4
    martixi[i][j]=1
    if and only if (i->j)
    0->1
    1->0
    1->2
    2->1
    2->3
    3->2
    3->1
    1->3
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int nodes = 4;
    int matrix[nodes][nodes] = {};

    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[2][3] = 1;
    matrix[3][2] = 1;
    matrix[3][1] = 1;
    matrix[1][3] = 1;

    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}