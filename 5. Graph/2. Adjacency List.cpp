#include <bits/stdc++.h>
using namespace std;

int number_of_vertices = 4;
vector<vector<int>> edges = {{0,2},{0,1},{0,3},{1,2},{1,3}};
int number_of_edges = edges.size();
vector<vector<int>> adj(number_of_vertices);

void makeAdj()
{
    for(int i=0; i<number_of_edges; i++)
    {
        int start = edges[i][0];
        int end = edges[i][1];
        adj[start].push_back(end);
        adj[end].push_back(start);
    }
}

void printAdj()
{
    for(int i=0; i<adj.size(); i++)
    {
        cout << "Node " << i << " Connected To ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    makeAdj();
    printAdj();
    return 0;
}
