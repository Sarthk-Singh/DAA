#include <iostream>
#include <vector>
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

void pathUsingDFS(vector<vector<int>> &adjList, int s, vector<int> &visited)
{
    visited[s] = 1;
    for (auto it : adjList[s])
    {
        if (!visited[it])
        {
            pathUsingDFS(adjList, it, visited);
        }
    }
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

    int start, destination;
    cout << "Enter the source node: ";
    cin >> start;
    cout << "Enter the destination node: ";
    cin >> destination;

    vector<int> visited(v, 0);
    pathUsingDFS(adjList, start, visited); // ✅ Run DFS from the source

    if (visited[destination])
        cout << "Yes, path exists" << endl;
    else
        cout << "No path exists" << endl;

    return 0;
}