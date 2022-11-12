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
}

vector<int> topologicalSort(int vertices, vector<vector<int>>& adj)
{
    vector<int> ans;
    vector<int> indegree(vertices);
    for(int i=0; i<adj.size(); i++)
    {
        for(auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for(int i=0; i<vertices; i++)
        if(indegree[i]==0) q.push(i);
    
    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto it : adj[front])
        {
            indegree[it]--;
            if(indegree[it]==0) 
                q.push(it);
        }
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
