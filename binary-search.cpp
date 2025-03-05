//binary search
#include <iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int>v,int target)
{
    int count=0;
    int low=0,high=v.size();
    while(low<=high)
    {
        count++;
        int mid=low+(high-low)/2;
        if(v[mid]==target)
            return count;
        else if(target<v[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}
int main()
{
    int n,target;
    cout<<"Enter the size of array" <<endl;
    cin>>n;
    cout<<"Enter the target"<<endl;
    cin>>target;
    vector<int>v(n);
    cout<<"Enter the elements into the array"<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int count=binarySearch(v,target);
    if(count>0)
        cout<<"Present "<<count<<endl;
    else
        cout<<"Not present"<<endl;
    return 0;
}