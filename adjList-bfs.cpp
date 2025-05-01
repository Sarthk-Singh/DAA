//BFS 
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void directedGraph(vector<vector<int>>&adjList,int e)
{
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
    }
}
void undirectedGraph(vector<vector<int>>&adjList,int e)
{
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
}
void printGraph(vector<vector<int>>adjList)
{
    int e=adjList.size();
    for(int i=0;i<e;i++)
    {
        cout << i << " -> ";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
}
void bfs(vector<vector<int>>&adjList,int s)
{
    int v=adjList.size();
    queue<int>q;
    q.push(s);
    vector<int>visited(v,0);
    visited[s]=1;
    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        cout << f << " ";
        for(auto it: adjList[f])
        {
            if(visited[it]==0)
            {
                q.push(it);
                visited[it]=1;
            }
        }
        // alternate loop technique
        //  for(int i=0;i<adjList[f].size();i++)
        //  {
        //      if(visited[adjList[f][i]]==0)
        //      {
        //          q.push(adjList[f][i]);
        //          visited[adjList[f][i]]=1;
        //      }
        //  }
    }
    
}
int main()
{
    int v,e;
    cout<<"Enter the number of vertices (0 based graph): ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    vector<vector<int>>adjList(v);
    undirectedGraph(adjList,e);
    printGraph(adjList);
    int start;
    cout<<"Enter the starting index for BFS: ";
    cin>>start;
    bfs(adjList,start);
    return 0;
}