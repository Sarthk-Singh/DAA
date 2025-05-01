#include <iostream>
#include<vector>
using namespace std;
int search(vector<int>v,int target)
{
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        count++;
        if(target==v[i])
        {
            return count;
        }
    }
    return 0;
}
int main()
{
    int n,target;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the target value to find"<<endl;
    cin>>target;
    cout<<"Enter the array elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int count=search(v,target);
    if(count>0)
        cout<<"Found "<<count<<endl;
    else
        cout<<"Not found\n"<<"Comparisons:"<<n<<endl;
    return 0;
}