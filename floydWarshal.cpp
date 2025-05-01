//floyd warshal's algorithm
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>> &graph)
{
    int v = graph.size();
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices and edges: ";
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

    floydWarshall(graph);

    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
