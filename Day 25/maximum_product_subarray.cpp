#include<algorithm>

int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    // Creating  variables
    int max_overall,max_ending_here,min_ending_here;
    /* Assign all the variables with arr[0] */
    
    max_overall = max_ending_here = min_ending_here = arr[0];
    
    
    for(int i=1;i<n;i++){
        
        // Assign temp to store the previous maximum
        int temp = max_ending_here;
        //Calculating max ending here
        max_ending_here = max({arr[i],arr[i]*temp,arr[i]*min_ending_here});
        
        //Calculating min ending here
        min_ending_here = min({arr[i],arr[i]*temp,arr[i]*min_ending_here});
        
        //Calculatingoverall maximum value
        max_overall =max(max_overall,max_ending_here);
    }
    return max_overall;
}


// Time Complexity : O(n)
// Space Complexity : O(1)