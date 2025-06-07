//detect cycle in a graph using dfs
#include <iostream>
#include <vector>
using namespace std;
bool isCycle(vector<vector<int>>&graph,int node,int parent,vector<int>&visited)
{
    visited[node]=1;
    for(auto it: graph[node])
    {
        if(!visited[it])
        {
            if(isCycle(graph,it,node,visited))
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
    cout<<"Enter the number of vertices and edges in the graph: "<<endl;
    cin>>v>>e;
    vector<vector<int>>graph(v);
    cout<<"Enter the edges: "<<endl;
    for(int i=0;i<v;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int start;
    cin>>start;
    vector<int>visited(v);
    bool ans=false;
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            if(isCycle(graph,start,-1,visited))
            {
                ans=true;
                break;
            }
        }
    }
    if(ans)
        cout<<"Cycle"<<endl;
    else
        cout<<"Not cycle"<<endl;
    return 0;
}