//prim's algorithm
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int prims(vector<vector<pair<int,int>>>&graph,int V,int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>vis(V,0);
    pq.push({0,start});
    int mst=0;
    while(!pq.empty())
    {
        int w=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(vis[u])
            continue;
        mst+=w;
        vis[u]=1;
        for(auto edge: graph[u])
        {
            int v=edge.first;
            int weight=edge.second;
            pq.push({weight,v});
        }
    }
    return mst;
}
void printGraph(const vector<vector<pair<int, int>>>& graph) {
    cout << "\nGraph Adjacency List:\n";
    for (int i = 0; i < graph.size(); ++i) {
        cout << i << " -> ";
        for (auto edge : graph[i]) {
            cout << "(" << edge.first << ", weight: " << edge.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges"<<endl;
    cin>>v>>e;
    vector<vector<pair<int,int>>>graph(v);
    cout<<"Enter the edges in the format: x -> y with weight"<<endl;
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    int start;
    cout<<"Enter the starting index for the spanning tree"<<endl;
    cin>>start;
    int minCost=prims(graph,v,start);
    cout<<"Min cost: "<<minCost<<endl;
    printGraph(graph);
    return 0;
}