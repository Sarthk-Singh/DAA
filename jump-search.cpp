//jump search
/*Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. 
Once the interval (arr[2k] <key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching):
Jump Search*/

#include <iostream>
#include <vector>
using namespace std;
bool linearSearch(int s, int e, vector<int> &v, int key, int &count)
{
    for (int i = s; i <= e; i++)
    {
        count++;
        if (v[i] == key)
            return true;
    }
    return false;
}
bool jumpSearch(vector<int> &v, int key, int &count)
{
    int n = v.size();
    int windowSize = 4;
    int s = 0, e = windowSize - 1;
    while (e < n)
    {
        count++;
        if (v[e] == key)
        {
            return true;
        }
        else if (v[e] < key)
        {
            s = e + 1;
            e += windowSize;
            if (e >= n)
                e = n - 1;
        }
        else
        {
            return linearSearch(s, e, v, key, count);
        }
    }
    return linearSearch(s, min(e, n - 1), v, key, count);
}
int main()
{
    int t;
    cout << "Enter Number of TestCases : ";
    cin >> t;
    vector<bool> groups(t);
    vector<int> compa(t);
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
        cout << endl;
        int count = 0;
        groups[i] = jumpSearch(v, key, count);
        compa[i] = count;
    }
    // Outputs:
    cout << "Outputs" << endl;
    for (int i = 0; i < t; i++)
    {
        if (groups[i])
        {
            cout << "Present , Comparisons : " << compa[i] << endl;
        }
        else
        {
            cout << "Not Present , Comparisons : " << compa[i] << endl;
        }
    }
}