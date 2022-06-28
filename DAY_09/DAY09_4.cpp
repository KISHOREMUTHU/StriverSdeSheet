// DAY 09
// QUESTION NO 4:Combination sum-2
// Question Explanation:Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.
//Note : This question is just a combination of last two sums(Q no: 2 and 3)
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
//Optimal Solution:
//Code:
void fun(int index ,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return ;
        }
        for(int i=index;i<arr.size();i++)
        {
            if(i>index && arr[i]==arr[i-1]) //to avoid duplicates
            {
                continue;
            }
            if(arr[i]>target) //if the current element is bigger than target then no need to check for net elements since the array is sorted
            {
                break;
            }
            ds.push_back(arr[i]);
            fun(i+1,target-arr[i],arr,ans,ds); //by including the current element 
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());//first we are sorting it to find duplicates
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0,target,candidates,ans,ds);
        return ans;
        
    }
/*Solution analysis:
 Time Complexity:O(2^n*k)  [Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take k average space for the ds.] 
Space Complexity:O(k*x)  [Reason: if we have x combinations then space will be x*k where k is the average length of the combination.]
*/

//Problem link: https://leetcode.com/problems/combination-sum-ii/ 