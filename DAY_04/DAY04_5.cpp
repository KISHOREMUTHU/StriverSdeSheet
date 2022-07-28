// DAY 4
// QUESTION NO : 5
// Question Explanation:Count the number of subarrays with given xor K
// Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to B.
//Brute fource :
//Check for all possible subarrays and update value
//code:
int solve(vector<int> &A, int B) 
{
    long int count=0;
    for(int i=0;i<A.size();i++)
    {
        int current_xor = 0;
        for(int j=i;j<A.size();j++) //we check for each subarray
        {
            current_xor^=A[j];  
            if(current_xor==B)
                count++;
        }
    }
    return count;
}


/*Solution analysis:
 Time complexsity: O(N^2) //becuz of two for loops 
 Auxillary space complexsity: O(1) 
 */
// ===================================================================
//Methord 2: Optimal
//Using prifxix sum and map
//code:
int Solution::solve(vector<int> &A, int B) 
{
    int count=0;
    int Xor=0;
    map<int,int> mapu;
    for(auto x:A)
    {
        Xor^=x;
        if(Xor==B)
            count++;
        if(mapu.find(Xor^B)!=mapu.end())
        {
            count+=mapu[Xor^B];
        }
        mapu[Xor]++;
    }
    return count;
    
}
/*Solution analysis:
 Time complexsity: O(NLogN) //one for loop and LogN for map
 Auxillary space complexsity: O(N)//for storing element in hashmap 
 */
// ===================================================================

//Problem Link: https://www.interviewbit.com/problems/subarray-with-given-xor/