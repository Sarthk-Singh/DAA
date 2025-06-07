#include <iostream>
#include <vector>
using namespace std;
int dfs(int s,int d,vector<vector<int>>&graph,int k)
{
    if(k==0&&u==v)
        return 0;
    if(k==1)
        return graph[u][v];
    if(k==0)
        return -1;
    int final=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(graph[u][v]!=INT_MAX&&s!=i&&d!=i)
        {

        }
    }
}
int main()
{
    int v, e;
    cout<<"Enter the v,e"<<endl;
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, INT_MAX));

    // Set 0 for self-loops
    for (int i = 0; i < v; i++)
        graph[i][i] = 0;

    cout << "Enter the edges in the format (u v w):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    return 0;
}