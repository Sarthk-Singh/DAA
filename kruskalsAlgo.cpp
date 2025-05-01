//week 8 question 2 lab minimum spanning tree
#include <iostream>
#include <vector>
using namespace std;

int find(int node, vector<int> &parent)
{
    if (node == parent[node])
        return node;
    else
        return parent[node] = find(parent[node], parent);
}
void union_by_rank(int x, int y, vector<int> &rank, vector<int> &parent)
{
    if (x == y)
        return;
    if (rank[x] == rank[y])
    {
        parent[x] = y;
        rank[y]++;
    }
    else if (rank[x] < rank[y])
        parent[x] = y;
    else
        parent[y] = x;

}
int main()
{
    int v, e;
    cout<<"Enter the v,e"<<endl;
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    cout << "Enter the edges of the graph" << endl;
    for (int i = 0; i < e; i++)
    {
        int w, x, y;
        cin>>w>>x>>y;
        edges.push_back({w, {x, y}});
    }
    sort(edges.begin(), edges.end());
    vector<int> parent(v);
    vector<int> rank(v);
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    int mst = 0;
    vector<pair<int, int>> ans;
    for (auto it : edges)
    {
        int w = it.first;
        int u = it.second.first;
        int v = it.second.second;

        int x = find(u, parent);
        int y = find(v, parent);
        if (x != y)
        {
            mst +=w;
            union_by_rank(x, y, rank, parent);
            ans.push_back({u, v});
        }
    }
    cout<<"Minimum weigth of spanning tree: "<<mst<<endl;
    cout<<"Edges of minimum spanning tree: "<<endl;
    for(auto it:ans)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    return 0;
}
/*
sample input
edges:
2 0 2
2 0 1
1 1 2
2 1 3
3 3 2
1 3 4
5 2 4
mst=6
*/