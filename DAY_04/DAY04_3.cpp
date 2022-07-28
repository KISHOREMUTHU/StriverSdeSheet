// DAY 4
// QUESTION NO :3
// Question Explanation:
// Longest Consecutive Sequence in an Array
// You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements.
// Input: [100, 200, 1, 3, 2, 4]
// Output: 4
// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.
//Methord 1:
//Sort the array and check for consecutive subsequence
 //code:
 int longestConsecutive(vector<int> nums) 
 {
        if(nums.size() == 0 ) //base case
        {
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int count = 1;
        
        for(int i = 1;i < nums.size();i++)
        {
            if(nums[i] == nums[i-1]) //compare current and previous element
            {
                count++;
            }
            else //if they are not same then reset count
            {
                count = 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
/*Solution analysis:
 Time complexsity: O(n log n) //for sorting
 Auxillary space complexsity: O(1) 
 */
// ===================================================================
//Methord 2:
//optimal
//we insert the values in a datastructure
//then we search for the starting number of the sequence then find the count do it for all other variables and then find the max of it and return the ans
//code:
int longestConsecutive(vector<int>& nums)
    {
        set<int> ds;
        int ans=0;
        for(auto x:nums)
        {
            ds.insert(x);
        }
        for(auto x:nums)
        {
            if(ds.find(x-1)==ds.end()) //we are trying to find the starting element of the sequence
            {
                int count=1;
                int temp=x;
                while(ds.find(temp+1)!=ds.end()) //we count till the seq continues
                {
                    count++;
                    temp++;
                }
                ans=max(ans,count);
                    
            }
        }
        return ans;
        
    }
/*Solution analysis:
 Time complexsity: O(n) 
 Auxillary space complexsity: O(n) //for storing the elements in the data structure
 */
// ===================================================================
//Problem Link: https://leetcode.com/problems/longest-consecutive-sequence/