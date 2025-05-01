//aggressive cows
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if we can place cows with at least 'minDist' apart
bool canPlaceCows(vector<int> &stalls, int k, int minDist)
{
    int cows = 1; // Place the first cow in the first stall
    int lastPlaced = stalls[0];

    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPlaced >= minDist)
        {
            cows++;
            lastPlaced = stalls[i];
            if (cows == k)
                return true;
        }
    }
    return false;
}

// Function to find the maximum minimum distance
int maxMinDistance(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end()); // Sort stall positions
    int low = 1, high = stalls.back() - stalls.front();
    int result = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, k, mid))
        {
            result = mid;
            low = mid + 1; // Try for a larger minimum distance
        }
        else
        {
            high = mid - 1; // Reduce the minimum distance
        }
    }
    return result;
}

int main()
{
    int n, k;
    cout << "Enter number of stalls: ";
    cin >> n;
    vector<int> stalls(n);

    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++)
    {
        cin >> stalls[i];
    }

    cout << "Enter number of cows: ";
    cin >> k;

    cout << "Maximum minimum distance: " << maxMinDistance(stalls, k) << endl;
    return 0;
}