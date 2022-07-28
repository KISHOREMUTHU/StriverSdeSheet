// DAY 4
// QUESTION NO : Two sum
// Question Explanation:Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.
//Example:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

//Approach:For each element, we try to find an element such that the sum of both elements is equal to the given targe
//Code:
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
   	 for (int j = i + 1; j < nums.size(); ++j) {
   		 if (nums[i] + nums[j] == target) {
   			 ans.push_back(i);
   			 res.push_back(j);
   			 break;
   		 }
   	 }
   	 if (ans.size() == 2)
   		 break;
    }
    return ans;
} 
/*Solution analysis:
 Time complexsity: O(N^2) 
 Auxillary space complexsity: O(1) 
 */
// ===================================================================

//Methord 2 :Using sorting and two pointer
//code:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        vector<int> temp;
        temp=nums;
        sort(temp.begin(),temp.end());
        int start=0,end=n-1;
        int num1,num2;
        while(start<end)
        {
            if(temp[start]+temp[end]==target)
            {
                num1=temp[start];
                num2=temp[end];
                break;
            }
            else if(temp[start]+temp[end]<target)
                start++;
            else
                end--;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                ans.push_back(i);
            else if(nums[i]==num2)
                ans.push_back(i);
            if(ans.size()==2)
                return ans;
        }
        return ans;
    }
/*Solution analysis:
 Time complexsity: O(N log N) //Because of sorting
 Auxillary space complexsity: O(N) //we use extra array for sorting (temp)
 */
// ===================================================================

//Methord 3 (Optimal solution)
//using hashmap
//code:
     vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
        {
            if(map.find((target-nums[i]))!=map.end())
            {
                ans.push_back(i);
                ans.push_back(map[(target-nums[i])]);
                return ans;
            }
            map[nums[i]]=i;
        }
        return ans;
    }
/*Solution analysis:
 Time complexsity: O(N) 
 Auxillary space complexsity: O(N) //we use Hashmap here so O(N)
 */
// ===================================================================

//Problem Link: https://leetcode.com/problems/two-sum/