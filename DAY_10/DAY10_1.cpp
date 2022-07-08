// DAY 10
// QUESTION NO 1: Print all permutation of a string / Array
// Question Explanation:Given an array arr of distinct integers, print all permutations of String/Array.
// Input: arr = [1, 2, 3]

// Output: 
// [
//   [1, 2, 3],
//   [1, 3, 2],
//   [2, 1, 3],
//   [2, 3, 1],
//   [3, 1, 2],
//   [3, 2, 1]
// ]

// Explanation: Given an array, return all the possible permutations.

//Brute Force using an extra data structure to check wheather an element occured in or not
//code:
void fun(vector<int>arr, vector<vector<int>>&ans,vector<int>&ds,bool map[])
    {
        if(ds.size()==arr.size())//base case when all the elements are filled
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(!map[i])//if we have not picked the element then pick it
            {
                map[i]=1;
                ds.push_back(arr[i]);
                fun(arr,ans,ds,map);
                ds.pop_back(); // after picking unpickit for next permutations
                map[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int>ds;
        bool map[nums.size()];
       for(int i=0;i<nums.size();i++)
           map[i]=false;
        fun(nums,ans,ds,map);
        return ans;
        
    }
/*Solution analysis:
 Time complexsity: O(N! * N) {N! for generation of Permutatuon in recursion and each for loop runs N times}
 Auxillary space complexsity: O(N) {N Space for the data structure} (We are ignoring the space taken by the recursion)
 */
// ===================================================================

//Optimal Solution: We are here removing the extra space we usend for the array Map

//We achive it by swapping
//We do swapping because every number should be at a particular index so we achive it by swapping instead of maping it

//code:

 void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size())//if the index pointer goes out of the range add it to the ans  
      {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]); //swap it for all possibilities 
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]); //reswap to bring it back to its original possition
      }
    }
    vector < vector < int >> permute(vector < int > & nums) {
      vector < vector < int >> ans;
      recurPermute(0, nums, ans);//this function does all the work
      return ans;
    }


/*Solution analysis:
 Time complexsity: O(N! * N) {N! for generation of Permutatuon in recursion and each for loop runs N times}
 Auxillary space complexsity: O(1) (We are ignoring the space taken by the recursion)
 */
// ===================================================================

//Problem link: https://leetcode.com/problems/permutations/