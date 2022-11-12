#include<bits/stdc++.h>
using namespace std;

int vertices = 4;
vector<vector<int>> edge = {{0,1},{0,2},{0,3},{1,2},{2,3}};
vector<int> adj[4];

void makeAdj()
{
    // Adjacency List
    for(int i=0; i<5; i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
}

void printAdj()
{
    cout << "Adjacency List" << endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";            
        }
        cout << endl;
    }
}

bool isCycleDFS(int curr, vector<int>& visited, vector<int> adj[], int parent)
{
    visited[curr] = 1;

    for(auto neigh : adj[curr])
    {
        if(!visited[neigh])
        {
            bool ans = isCycleDFS(neigh, visited, adj, curr);
            if(ans)
                return true;
        }
        else if(neigh != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int vertices,  vector<int> adj[])
{
    vector<int> visited(vertices);
    int parent;
    for(int i=0; i<vertices; i++)
    {
        bool ans = isCycleDFS(0, visited, adj, parent);
        if(ans)
            return true;
    }
    return false;
}

int main()
{
    makeAdj();
    bool ans;
    ans = isCycle(vertices, adj);
    cout << ans << endl;
    return 0;
}
