#include <iostream>
#include <vector>
#include <queue>
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

bool isBipartite(vector<vector<int>> &adjList, vector<int> &visited, int s)
{
    int v = adjList.size();
    vector<int> colour(v, -1);

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    colour[s] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto it : adjList[front])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
                colour[it] = !colour[front];
            }
            else if (colour[it] == colour[front])
            {
                return false;
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
    undirectedGraph(adjList, e);
    printGraph(adjList);

    vector<int> visited(v, 0);
    bool ans = true;

    // Handle disconnected graph by checking all components
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            if (!isBipartite(adjList, visited, i))
            {
                ans = false;
                break;
            }
        }
    }

    if (!ans)
        cout << "NOT BIPARTITE!!" << endl;
    else
        cout << "BIPARTITE DETECTED!!" << endl;

    return 0;
}
