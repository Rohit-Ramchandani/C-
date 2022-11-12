#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> edges = {{0,2},
                             {0,1},
                             {0,3},
                             {1,2},
                             {1,3}};
    int number_of_edges = edges.size();
    int adj[4][4];
    memset(adj, 0, sizeof(adj));
    for(int i=0; i<number_of_edges; i++)
    {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1; 
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout << adj[i][j] << " ";    
        cout << endl;
    }
    return 0;
}
