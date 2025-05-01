#include <iostream>
#include<vector>
using namespace std;
void undirectedGraph(vector<vector<int>> &adjList, int e)
{
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
}
void directedGraph(vector<vector<int>> &adjList, int e)
{
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }
}
void printGraph(vector<vector<int>> adjList)
{
    int v = adjList.size();
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << endl;
    }
}
void dfs(vector<vector<int>>&adjList,int s,vector<int>&visited)
{
    cout<<s<<" ";
    visited[s]=1;
    for(auto it: adjList[s])
    {
        if(!visited[it])
            dfs(adjList,it,visited);
    }
    //alternate loop technique
    // for (int i = 0; i < v; i++)
    // {
    //     if (visited[i] == 0)
    //         dfsUtil(adjList, visited, i);
    // }
}
int main()
{
    int v, e;
    cout << "Enter the number of vertices (0 based graph): ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<int>> adjList(v);
    undirectedGraph(adjList, e);
    printGraph(adjList);
    int start;
    cout << "Enter the starting index for DFS: ";
    cin >> start;
    vector<int>visited(v,0);
    dfs(adjList, start,visited);
    return 0;
}