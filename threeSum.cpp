#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>>bruteMethod(vector<int> &nums)
{
    int size = nums.size();
    vector<vector<int>> trip;

    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int z = j + 1; z < size; z++)
            {
                if (nums[i] + nums[j] + nums[z] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[z]};
                    sort(temp.begin(), temp.end());

                    if (find(trip.begin(), trip.end(), temp) == trip.end())
                    {
                        trip.push_back(temp);
                    }
                }
            }
        }
    }
    return trip;
}
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    
    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicates for first element
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        int left = i + 1;   
        int right = n - 1;
        
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0)
            {
                res.push_back({nums[i], nums[left], nums[right]});
                
                // Skip duplicates for left and right
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                
                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return res;
}
int main()
{
    int n;
    cout<<"Enter the size fp array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the elements into the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    vector<vector<int>>ans=threeSum(nums);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

