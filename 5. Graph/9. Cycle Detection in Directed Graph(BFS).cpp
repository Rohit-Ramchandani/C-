#include<bits/stdc++.h>
using namespace std;

int vertices = 8;
vector<vector<int>> edge = {{0,1},{1,2},{1,3},
                            {3,4},{4,5},{5,3},
                            {2,6},{2,7},{7,8}};
int edges = edge.size();
vector<vector<int>> adj(vertices);

void makeadj()
{
    for(int i=0; i<edges; i++)
    {
        int start = edge[i][0];
        int end = edge[i][1];
        adj[start].push_back(end);
    }
}

bool topologicalSort(int vertices, vector<vector<int>>& adj)
{
    int count;
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
    return count == vertices;
}

int main()
{
    makeadj();
    vector<int> visited(vertices);
    return 0;
}