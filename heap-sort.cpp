#include <iostream>

using namespace std;

void heapify(int *arr,int i,int n)
{
    int parent=i;
    int left=i*2;
    int right=i*2+1;
    if (left<=n&&arr[left]>arr[parent])
    {
        parent=left;
    }
    if(right<=n&&arr[right]>arr[parent])
    {
        parent=right;
    }
    if(parent!=i)
    {
        swap(arr[parent],arr[i]);
        heapify(arr,parent,n);
    }
}
void heapSort(int *arr,int n)
{
    for (int i = n/2; i>=1; i--)
    {
        heapify(arr,i,n);
    }
    for (int i = n-1; i >n; i--)
    {
        swap(arr[1],arr[i]);
        heapify(arr,1,i-1);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"Enter the elements in array"<<endl;
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    heapSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}