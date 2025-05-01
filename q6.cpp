#include <iostream>
#include <vector>
#include <map>
using namespace std;
void difference(vector<int> &v, int key, vector<int> &counts)
{
    map<int, int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]] = i;
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int diff = key;
        int found = v[i] + diff;
        if (mp.find(found) != mp.end())
        {
            count++;
        }
    }
    counts.push_back(count);
}
int main()
{
    int k;
    cout << "Number of Test Cases : ";
    cin >> k;
    vector<int> counts;
    for (int i = 0; i < k; i++)
    {
        int n;
        cout << "Enter the Number of Elements : ";
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int key;
        cout << "Enter the key :";
        cin >> key;
        difference(v, key, counts);
    }
    cout << endl;
    cout << "Output : " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << counts[i] << endl;
    }
}
