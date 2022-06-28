// DAY 09
// QUESTION NO 1: Subset sums
// Question Explanation:Create all possible subsets store their sum and return it from the given array
// Input:
// N = 2
// arr[] = {2, 3}
// Output:
// 0 2 3 5
// Explanation:
// When no elements is taken then Sum = 0.
// When only 2 is taken then Sum = 2.
// When only 3 is taken then Sum = 3.
// When element 2 and 3 are taken then 
// Sum = 2+3 = 5

//Optimal solution
//explanation:We iterate recursively for all the subsets along with a variable sum which includes the current element and without the current element
void Generator(int start,int sum,vector<int>&arr,vector<int>&ans)
    {
        if(start==arr.size()) //Base case 
        {
            ans.push_back(sum);
            return;
        }
        Generator(start+1,sum+arr[start],arr,ans);//we include the current element in the sum and call the recusion
        Generator(start+1,sum,arr,ans);//without the current element in the sum and call the recusion
        
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
       vector<int> ans;
       Generator(0,0,arr,ans);//this function does the entire work as we pass through reference
       sort(ans.begin(),ans.end());//for the sake for sorting (because of the question)
       return ans;
    }

/*Solution analysis:
 Time complexsity: O(2^n) {if we consider the sorting also then Time complexsity is:O(2^n*Log(2^n))}
 Auxillary space complexsity: O(2^n)  [for storing subset sums, since 2^n subsets can be generated for an array of size n.]
//  *

//  Problem Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#
//  Blog: https://takeuforward.org/data-structure/subset-sum-sum-of-all-subsets/ 