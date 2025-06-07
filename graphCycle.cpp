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
<<<<<<< HEAD
bool checkCycle(vector<vector<int>>&adjList,int s,int parent,vector<int>&visited)
{
    visited[s]=1;
    for(auto it: adjList[s])
    {
        if(!visited[it])
        {
            if(checkCycle(adjList,it,s,visited))
=======
bool checkCycle(vector<vector<int>>&adjList,int node,int parent,vector<int>&visited)
{
    visited[node]=1;
    for(auto it: adjList[node])
    {
        if(!visited[it])
        {
            if(checkCycle(adjList,it,node,visited))
>>>>>>> c94b8784b852750e01e0819a98f75e1200e52c6a
                return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
}

int main()
{
    int v,e;
    cout<<"Enter the number of vertices(0 based graph): ";
    cin >> v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    
    vector<vector<int>>adjList(v);
    undirectedGraph(adjList,e);
    printGraph(adjList);
    
    vector<int>visited(v,0);
    bool ans=false;
    //in case of disconnected graph call dfs function on every node of the graph
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(checkCycle(adjList,i,-1,visited))
<<<<<<< HEAD
                ans=true;            
=======
            {
                ans=true;            
                break;
            }
>>>>>>> c94b8784b852750e01e0819a98f75e1200e52c6a
        }
    }
    
    if(ans)
        cout<<"CYCLE DETECTED!!"<<endl;
    else
        cout<<"NO CYCLE DETECTED"<<endl;
    return 0;
}