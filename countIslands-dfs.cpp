#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &grid, int x, int y)
{
    // Check boundaries and if it's water (0)
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
        return;

    grid[x][y] = 0; // Mark visited

    // Explore all four directions
    dfs(grid, x + 1, y); // Down
    dfs(grid, x - 1, y); // Up
    dfs(grid, x, y + 1); // Right
    dfs(grid, x, y - 1); // Left
}

int countIslands(vector<vector<int>> &grid)
{
    int count = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            { // Found new island
                count++;
                dfs(grid, i, j); // Sink the island
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 0, 0}};

    cout << "Number of Islands: " << countIslands(grid) << endl;
    return 0;
}
