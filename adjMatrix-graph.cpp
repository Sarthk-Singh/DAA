//Adjecency matrix based graph
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int v,e;
    cout<<"Enter the number of vertices (0 based grapgh): ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    
    for(int i=0;i<e;i++)
    {
        int u,v1;
        cout<<"Enter the source vertex and destination vertex for edge "<<i+1<<": ";
        cin>>u>>v1;
        if (u >= 0 && u < v && v1 >= 0 && v1 < v)
        {
            graph[u][v1] = 1;
            graph[v1][u] = 1; // For undirected graph
        }
        else
        {
            cout << "Invalid edge! Please enter vertices between 0 and " << v - 1 << endl;
            i--; // Re-enter the edge
        }
        
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }

    return 0;
}