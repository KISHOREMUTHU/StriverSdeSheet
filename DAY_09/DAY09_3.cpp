// DAY 09
// QUESTION NO 3: Combination Sum 1 
// Question Explanation:Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// Input: array = [2,3,6,7], target = 7

// Output: [[2,2,3],[7]]

// Explanation: 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//              7 is a candidate, and 7 = 7.
//              These are the only two combinations.
    void fun(int i ,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        if(target==0) //when we got the required sum in ds
        {
            ans.push_back(ds);
            return;
        }
        if(i==arr.size()) //when we iterate entirely through the last
        {
            return;
        }
        if(arr[i]<=target) 
        {
            ds.push_back(arr[i]);
            fun(i,target-arr[i],arr,ans,ds); //here we go for the same element again
            ds.pop_back();
        }
        fun(i+1,target,arr,ans,ds); //we go for next element
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        fun(0,target,candidates,ans,ds);
        return ans;
    }
/*Solution analysis:
 Time Complexity: O( (2^t) * k)  [Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
        Why not (2^n) but (2^t) (where n is the size of an array)?
        Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.] 
        for Further understanding Refer: https://leetcode.com/problems/combination-sum/discuss/1755084/Detailed-Time-and-Space-Complecity-analysisc%2B%2Bjavabacktracking
 Auxillary space complexsity: O(x*k)  [k is the average length and x is the no. of combinations]
*/
//Problem Link: https://leetcode.com/problems/combination-sum/ 