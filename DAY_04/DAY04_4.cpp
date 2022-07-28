// DAY 4
// QUESTION NO : 4
// Question Explanation:Largest Subarray with 0 sum
//naive approach : Check for each subarray sum if its equal to zero store the length and find the length and return max length
//Question:Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.
//array[] = {9, -3, 3, -1, 6, -5}
//o/p: 5
//Brute force:
//code:
int maxLen(vector<int>&A, int n)
    {   
        int max1=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=A[j];
                if(sum==0)
                {
                    max1=max(max1,j-i+1);
                }
            }
        }
        return max1;
    }
/*Solution analysis:
 Time complexsity: O(N^2) //because of two for loops
 Auxillary space complexsity: O(1) 
 */
// ===================================================================
//Optimal approach (using hashing and prefix sum)
//code:
int maxLen(vector<int>&A, int n)
    {   
        map<int,int> mapu;
        int sum=0;
        int size=0;
        for(int i=0;i<n;i++)
        {
            sum+=A[i];
            if(sum==0)
            {
                size=i+1;
            }
            else
            {
                if(mapu.find(sum)==mapu.end())
                {
                    mapu[sum]=i;
                }
                else
                {
                    size=max(size,i-mapu[sum]);
                }
            }
        }
        return size;
    }
/*Solution analysis:
 Time complexsity: O(NlogN) //N for loop , LogN for mapu (searching)
 Auxillary space complexsity: O(N) //because of mapu
 */
// ===================================================================
//Problem Link:https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1