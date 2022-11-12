#include<bits/stdc++.h>
using namespace std;

int vertices = 8;
vector<vector<int>> edge = {{0,1},{1,3},{1,2},
                            {2,6},{2,7},{7,6},
                            {3,4},{4,5},{5,3}};
int edges = edge.size();
vector<vector<int>> adj(vertices);

void makeAdj()
{
    for(int i=0; i<edges; i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];
        adj[start].push_back(end);
    }
}

bool isCycleDirectedDFS(int node, vector<int>& visited, vector<int>& dfsvisited, vector<vector<int>> adj)
{
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(auto neigh : adj[node])
    {
        if(!visited[neigh])
        {
            bool ans = isCycleDirectedDFS(neigh, visited, dfsvisited, adj);
            if(ans)
                return true;
        }
        else if(dfsvisited[neigh])
        {
            return true;
        }
    }

    dfsvisited[node] = 0;
    return false;
}

bool isCycleDirected(int vertices, vector<vector<int>>& adj)
{
    vector<int> visited(vertices);
    vector<int> dfsvisited(vertices);
    for(int i=0; i<vertices; i++)
    {
        if(!visited[i])
        {
            bool ans = isCycleDirectedDFS(i, visited, dfsvisited, adj);
            if(ans)
                return true;
        }
    }
    return false;
}

int main()
{
    makeAdj();

    //call DFS for all components
    bool ans = isCycleDirected(vertices, adj);
    cout << ans << endl;
    return 0;
}
