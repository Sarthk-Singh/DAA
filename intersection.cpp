#include <iostream>
#include <vector>
#include <algorithm> // Added for sorting

using namespace std;

void intersection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> intersection;

    // Ensure both arrays are sorted
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] == arr2[j])
        {
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    if (intersection.empty())
    {
        cout << "No common elements found";
    }
    else
    {
        for (int num : intersection)
        {
            cout << num << " ";
        }
    }
}

int main()
{
    int n1, n2;
    cout << "Enter the number of elements in the first array: ";
    cin >> n1;
    vector<int> array1(n1);
    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; ++i)
    {
        cin >> array1[i];
    }

    cout << "Enter the number of elements in the second array: ";
    cin >> n2;
    vector<int> array2(n2);
    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; ++i)
    {
        cin >> array2[i];
    }

    cout << "Intersection: ";
    intersection(array1, array2);

    return 0;
}
