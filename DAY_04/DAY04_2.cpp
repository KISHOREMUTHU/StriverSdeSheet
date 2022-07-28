// DAY 04
// QUESTION NO : Four sum
// Question Explanation:Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]]
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
//Methord 1:
//Approach: we simply iterate through the array for all possible combination using four loops and find the values 
// here we also remove duplicates by inserting them into a data structure such as set
//code:
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>>ans;
        int n=nums.size();
        if(n<4)
            return ans;
    set<vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=j+!1;k<n;k++)
            {
                for(int l=k+1;k<n;k++)
                {
                    if((long long int)nums[i]+nums[j]+nums[k]+nums[l]==target)
                    {
                        vector<int>vec={nums[i],nums[j],nums[k],nums[l]};
                        sort(vec.begin(),vec.end());
                        temp.insert(vec);
                    }
                }
            }
        }
    }
    for(auto x:temp)
        ans.push_back(x);
    return ans;

}

/*Solution analysis:
 Time complexsity: O(N^4)  
 Auxillary space complexsity: O(n) //for the data structure set 
 */
// ===================================================================

//Methord 2: We sort the array select two elements and find the other twwo numbers as we found in two sum problem
//optimal Solution:
//code:
 vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>>ans;
        int n=nums.size();
        if(n<4)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int left=j+1;
                int right=n-1;
                while(left<right)
                {
                    if((long long int)nums[i]+nums[j]+nums[left]+nums[right]==target)
                    {
                        vector<int> temp={nums[i],nums[j],nums[left],nums[right]};
                        ans.push_back(temp);
                         while(left+1<right and nums[left]==nums[left+1])
                            left++;
                        left++;
                        while(right-1>left and nums[right]==nums[right-1])
                           right--;
                        right--;
                    }
                    else if((long long int)nums[i]+nums[j]+nums[left]+nums[right]<target)
                    {
                        while(left+1<right and nums[left]==nums[left+1])
                            left++;
                        left++;
                    }
                    else
                    {
                       while(right-1>left and nums[right]==nums[right-1])
                           right--;
                        right--;
                    }
                }
                while(j+1<n and nums[j]==nums[j+1])
                    j++;
                    
            }
            while(i+1<n and nums[i]==nums[i+1])
                i++;
        }
        return ans;
        
    }
/*Solution analysis:
 Time complexsity: O(N^3) //for loop O(n^2) while loop O(n) 
 Auxillary space complexsity: O(1) 
 */
// ===================================================================

//Problem Link:https://leetcode.com/problems/4sum/