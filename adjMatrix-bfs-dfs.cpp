// Adjacency matrix-based graph with BFS + DFS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, int s, int v, vector<int> visited)
{
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    cout << "BFS Traversal: ";
    while (!q.empty()) // FIXED CONDITION
    {
        int f = q.front();
        q.pop();
        cout << f << " ";

        // Traverse all possible nodes
        for (int i = 0; i < v; i++)
        {
            if (graph[f][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void dfs(vector<vector<int>>&graph,int s,int v,vector<int>&visited)
{
    cout<<s<<" ";
    visited[s]=1;

    for (int i = 0; i < v; i++) // Traverse all possible nodes
    {
        if (graph[s][i] == 1 && visited[i] == 0)
        {
            dfs(graph, i, v, visited);
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices (0-based graph): ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    // Initialize adjacency matrix
    vector<vector<int>> graph(v, vector<int>(v, 0));

    for (int i = 0; i < v; i++) //setting diagonal as 1
    {
        graph[i][i] = 1;
    }

    for (int i = 0; i < e; i++) // Input edges
    {
        int u, v1;
        cout << "Enter the source vertex and destination vertex for edge " << i + 1 << ": ";
        cin >> u >> v1;

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

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    vector<int> visited(v, 0);
    int s;
    cout << "Enter the starting index of BFS: ";
    cin >> s;
    
    // Run BFS
    bfs(graph, s, v,visited);
    cout << "DFS Traversal: ";
    dfs(graph, s, v,visited);
    return 0;
}
