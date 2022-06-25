// DAY 12 
// QUESTION NO 1: Check if a number if a power of 2 or not in O(1) 
//  BRUTE FORCE APPROACH
//  Explanation:
//     if a number is power of two then if we keep on dividing the number but 2 after Nth time we get zero
// if anywhere thius condition fails then its not a power of 2
 bool isPowerOfTwo(int n)
 {
    if(n==0) //edge case because 0 will not enter the while loop and it will return true but 0 is not power of 2
        return false;
    while(n!=1)
    {
        if(n%2!=0) //to check if the number is divisible by 2 or not
            return false; //if number is not divisible by 2 then return false
        n=n/2;
    }
    return true;
 }

 /*Solution analysis:
 Time complexsity: O(log2(n)) [REASON: SINCE WE KEEP ON DIVIDING BY 2 WE GET LOG2(N)]
 Auxillary space complexsity: O(1)
 */

//=======================================================================================
//OPTIMAL SOLUTION:
//  POINTS TO NOTE:
//     FOR A NUMBER TO BE A POWER OF 2 IT SHOULD CONTAIN ONLY ONE SET BIT IN ITS BINARY REPRESENTATION
//  SO THE OPTIMAL SOLUTION IS THE ONE BASED ON BIT MANIPULATION.
// WE are going to check where only one bit is set by using Brian Kernighan’s algorithm
// Refernce: https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
// HOW IT WORKS?
//     CONSIDER A NUMBER N=32 (POWER OF 2)
//     IN BINARY FORM => 00010000
//     WE TAKE N-1 = 31
//     IN BINARY FORM => 00001111
//     IF WE DO LOGICAL AND BETWEEN THESE TWO THEN WE GET zero ONE AND ONLY IF THE NUMBER IS IN POWER OF 2 ONLY ONE SET BIT
//     N & (N-1)=0 
// LETS CONSIDER FOR N=40 (NOT A POWER OF TWO)
//     IN BINARY FORM => 101000
//     N-1=39
//     IN BINARY FORM => 100111
//     N & (N-1)=100000 B = 32 !=0
bool isPowerOfTwo(int n)
 {
    if(n==0)
        return false;
    if(n & (n-1)==0) 
        return true;
    return false;
 }
  /*Solution analysis:
 Time complexsity: O(1) 
 Auxillary space complexsity: O(1)
 */
//  Similar problems:
//  Count total set bits (discussed as next using same Brain's Algorithm )
//===========================================================================