#include <iostream>
#include <algorithm>
using namespace std;
//xyz
int findMinPlatforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n)
    {
        if (arr[i] <= dep[j]) // A new train arrives before the previous one departs
        { 
            platforms++;
            i++;
        }
        else // A train departs
        { 
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}

int main()
{
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    int arr[n], dep[n];
    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter departure times: ";
    for (int i = 0; i < n; i++)
        cin >> dep[i];

    cout << "Minimum number of platforms required: " << findMinPlatforms(arr, dep, n) << endl;
    return 0;
}
