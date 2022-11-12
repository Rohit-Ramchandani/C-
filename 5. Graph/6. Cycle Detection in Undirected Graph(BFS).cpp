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

bool isCycleBFS(int curr, vector<int>& visited, vector<int> adj[], vector<int>& parent)
{
    parent[curr] = -1;
    visited[curr] = 1;
    queue<int> q;
    q.push(curr);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neigh : adj[front])
        {
            if(visited[neigh] && neigh != parent[front])
            {
                return true;
            }
            else
            {
                q.push(neigh);
                visited[neigh] = 1;
                parent[neigh] = front;
            }
        }
    }
    return false;
}

bool isCycle(int vertices,  vector<int> adj[])
{
    vector<int> visited(vertices);
    vector<int> parent(vertices);    
    for(int i=0; i<vertices; i++)
    {
        bool ans = isCycleBFS(0, visited, adj, parent);
        if(ans)
            return true;
    }
    return false;
}

int main()
{
    makeAdj();
    //printAdj();

    bool ans;
    ans = isCycle(vertices, adj);
    cout << ans << endl;
    return 0;
}
