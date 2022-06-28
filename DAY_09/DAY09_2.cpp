// DAY 09
// QUESTION NO 2:  Subset-II
// Question Explanation:Given an array of integers that may contain duplicates the task is to return all possible subsets. Return only unique subsets and they can be in any order.
// Input: array[] = [1,2,2]

// Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

// Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.
//Brute force 
//As we did in previous sum(DAY09_1) generate All possisble subset but first sort the subsets among themselves and insert them into a set datatype thus we can prevent duplicate here
//CODE
    void Generator(vector < int > & nums, int index, vector < int > ds, set < vector < int >> & res) {
      if (index == nums.size())
      {
        sort(ds.begin(), ds.end());//sort the obtained subset
        res.insert(ds);//insert into the set (note:Set doesn't contains duplicates)
        return;
      }
      //same as we did in previous sum(very important pattern we will use this to solve many recursion problem)
      ds.push_back(nums[index]);
      Generator(nums, index + 1, ds, res);
      ds.pop_back();
      Generator(nums, index + 1, ds, res);
    }
  vector < vector < int >> subsetsWithDup(vector < int > & nums) 
  {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    Generator(nums, 0, ds, res);//this function does all the work
    for (auto x: res) //we have the answer in set but they asked us to return in vector so we convert it into vector
    {
      ans.push_back(x);s
    }
    return ans;
  } 
/*Solution analysis:
 Time Complexity: O( 2^n *(k log (x)))  [Reason: 2^n for generation of subsets and klog(x) for inserting the element in set data structure] 
 Auxillary space complexsity: O(2^n * k)  [for storing subset sums, since 2^n subsets can be generated for an array of size n with average length of subset as K]
*/
//==============================================================================
//Optial approach
 void Generator(int index,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds)
    {
        ans.push_back(ds);
        for(int i=index;i<arr.size();i++) //this is a new pattern
        {
            if(i>index && arr[i]==arr[i-1])//check for duplicates if present skip that number
                continue;
            ds.push_back(arr[i]); //with element
            Generator(i+1,arr,ans,ds); 
            ds.pop_back(); //without element
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>ds;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());//first we sort the given array
        Generator(0,nums,ans,ds);
        return ans;
        
    }
/*Solution analysis:
 Time Complexity: O( 2^n * K)  [Reason: 2^n for generation of subsets and k for inserting the element in data structure] 
 Auxillary space complexsity: O(2^n * k)  [for storing subset sums, since 2^n subsets can be generated for an array of size n with average length of subset as K]
*/
 //problem Link: https://leetcode.com/problems/subsets-ii/