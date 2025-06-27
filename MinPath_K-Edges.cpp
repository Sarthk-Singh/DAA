#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dfs(int s, int d, vector<vector<int>> &graph, int k)
{
    if (k == 0 && s == d)
        return 0;
    if (k == 0)
        return INT_MAX;
    if (k == 1)
        return graph[s][d];

    int minCost = INT_MAX;

    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[s][i] != INT_MAX)
        { // There is an edge from s to i
            int temp = dfs(i, d, graph, k - 1);
            if (temp != INT_MAX)
                minCost = min(minCost, graph[s][i] + temp);
        }
    }

    return minCost;
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices and edges:\n";
    cin >> v >> e;
    vector<vector<int>> graph(v, vector<int>(v, INT_MAX));

    for (int i = 0; i < v; i++)
        graph[i][i] = 0;

    cout << "Enter the edges in the format (u v w):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    int s, d, k;
    cout << "Enter source, destination and number of edges (k):\n";
    cin >> s >> d >> k;

    int result = dfs(s, d, graph, k);
    if (result == INT_MAX)
        cout << "No path of length " << k << " exists between " << s << " and " << d << ".\n";
    else
        cout << "Minimum cost from " << s << " to " << d << " with " << k << " edges is: " << result << "\n";

    return 0;
}
