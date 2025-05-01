/* Given a sorted array of positive integers containing few duplicate elements, design an algorithm and
implement it using a program to find whether the given key element is present in the array or not. If present,
then also find the number of copies of given key. (Time Complexity = O(log n))*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
void duplicateFind(vector<int> &v, int key, vector<bool> &results, vector<int> &counts, int index)
{
    map<int, int> mp;
    for (int num : v)
    {
        mp[num]++;
    }
    if (mp.find(key) != mp.end())
    {
        results[index] = true;
        counts[index] = mp[key];
    }
    else
    {
        results[index] = false;
        counts[index] = 0;
    }
}
int main()
{
    int t;
    cout << "Enter Number of Test Cases: ";
    cin >> t;
    vector<bool> results(t);
    vector<int> counts(t);
    for (int i = 0; i < t; i++)
    {
        int n;
        cout << "Enter the Number of Elements : ";
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }
        int key;
        cout << "Enter the Key : ";
        cin >> key;
        duplicateFind(v, key, results, counts, i);
    }
    cout << "Outputs" << endl;
    for (int i = 0; i < t; i++)
    {
        if (results[i])
            cout << "Present , Count: " << counts[i] << endl;
        else
            cout << "Not Present" << endl;
    }
    return 0;
}