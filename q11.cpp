#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int s, int e, int &comparisons, int &swaps)
{
    int pivot = v[e];
    int i = s - 1;

    for (int j = s; j < e; j++)
    {
        comparisons++;
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
            swaps++;
        }
    }
    swap(v[i + 1], v[e]);
    swaps++;

    return i + 1;
}

void quickSort(vector<int> &v, int s, int e, int &comparisons, int &swaps)
{
    if (s >= e)
        return;

    int par = partition(v, s, e, comparisons, swaps);
    quickSort(v, s, par - 1, comparisons, swaps);
    quickSort(v, par + 1, e, comparisons, swaps);
}

int main()
{
    int t;
    cout<<"Enter the number of test cases:";
    cin >> t;

    vector<vector<int>> groups;
    vector<int> comps(t);
    vector<int> swapss(t);

    for (int i = 0; i < t; i++)
    {
        int n;
        cout << "\nEnter size of array: ";
        cin >> n;
        vector<int> temp(n);
        cout << "Enter elements in the array: ";
        for (int j = 0; j < n; j++)
        {
            cin >> temp[j];
        }
        int comp = 0, swaps = 0;
        quickSort(temp, 0, n - 1, comp, swaps);

        groups.push_back(temp);
        comps[i] = comp;
        swapss[i] = swaps;
    }

    cout << "\nOutput:\n";
    for (int i = 0; i < t; i++)
    {
        for (int num : groups[i])
        {
            cout << num << " ";
        }
        cout << "\nComparisons: " << comps[i] << " Swaps: " << swapss[i] << endl;
    }
    return 0;
}
