// bipatite graph problem using bfs
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1); // -1 = unvisited

    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (int neighbor : graph[node])
                {
                    if (color[neighbor] == -1)
                    {
                        color[neighbor] = 1 - color[node]; // Alternate color
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node])
                    {
                        return false; // Conflict in coloring
                    }
                }
            }
        }
    }

    return true;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices (0-based index): ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adjList(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    if (isBipartite(adjList))
        cout << "Bipatite graph!!\n";
    else
        cout << "Not Bipatite Graph!!\n";
    return 0;
}