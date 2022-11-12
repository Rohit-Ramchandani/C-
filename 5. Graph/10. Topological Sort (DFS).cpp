#include<bits/stdc++.h>
using namespace std;
/*
1. Topological sort can only be applied on Directed Acyclic Graph(D.A.G).
2. Directed Acyclic Graph is a graph without any cycle.
*/

void makeadj(vector<vector<int>> edge,vector<vector<int>>& adj)
{
    int edges = edge.size();
    for(int i=0; i<edges; i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];
        adj[start].push_back(end);
    }
    /*
    for(int i=0; i<adj.size(); i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    */
}

void toposort(int node, vector<int>& visited, stack<int>& stk, vector<vector<int>>& adj)
{
    visited[node] = 1;

    for(auto neigh : adj[node])
    {
        if(!visited[neigh])
        {
            toposort(neigh, visited, stk, adj);
        }
    }

    // Important step
    stk.push(node);

}

vector<int> topologicalSort(int vertices, vector<vector<int>>& adj)
{
    vector<int> visited(vertices);
    stack<int> stk;

    // Call DFS topological sort util function for all nodes
    for(int i=0; i<vertices; i++)
    {
        if(!visited[i])
            toposort(i, visited, stk, adj);
    }

    vector<int> ans;
    while(!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main()
{
    int vertices = 6;
    vector<vector<int>> edge = {{0,1},{0,2},{1,3},
                                {2,3},{3,4},{4,5}};
    vector<vector<int>> adj(vertices);

    makeadj(edge, adj);

    vector<int> ans;
    ans = topologicalSort(vertices, adj);

    for(auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}