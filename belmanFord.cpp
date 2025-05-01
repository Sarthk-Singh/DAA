
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool bellmanFord(int V, int start, vector<vector<pair<int, int>>> &graph, vector<int> dist)
{
    dist.assign(V, INT_MAX);
    dist[start] = 0;
    // relax all edges v-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            if (dist[u] == INT_MAX) // skip if not reachable
                continue;
            for (auto it : graph[u])
            {
                int v = it.first;
                int w = it.second;
                if (dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }
    // check for negative weight cycle
    for (int u = 0; u < V; u++)
    {
        if (dist[u] == INT_MAX)
            continue;
        for (auto it : graph[u])
        {
            int v = it.first;
            int w = it.second;
            if (dist[u] + w < dist[v])
                return false; // negative cycle
        }
    }
    return true;
}
int main()
{
    int v, e;
    cout << "Enter the number of edges and vertices" << endl;
    cin >> v >> e;
    vector<vector<pair<int, int>>> graph(v);
    cout << "Enter the edges of the graph" << endl;
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }
    int start;
    cout << "Enter the starting node\n";
    cin >> start;
    vector<int> dist;
    if (bellmanFord(v, start, graph, dist))
    {
        cout << "Shortest distances from the starting node:\n";
        for (int i = 0; i < v; i++)
        {
            cout << "Distance to node " << i << ": " << dist[i] << endl;
        }
    }
    return 0;
}