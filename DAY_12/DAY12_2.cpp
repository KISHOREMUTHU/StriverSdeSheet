// DAY 12 
// QUESTION NO 2:  Count total set bits
// Question Explanation:
// IF THE NUMBER IS 25
// THE NUMBER IN BINARY FORMS: 11001
// OUR WORK TO COUNT THE NUMBER OF ONE'S IN THE BINARYN FORM OF THE NUMBER
// HERE ITS : 3 
//  BRUTE FORCE APPROACH
//we just check for each and every bit untill n becomes zero
int countSetBit (int n)
{
    int ans=0;
    while(n)
    {
        if(n&1==1) //checking for the last bit is set or not 
            ans++;
        n=(n>>1); //we performing rigth shift so the binary change from xxxxxyz to 0xxxxxy
        //alter for n=(n>>1); is n=n/2;  
    }
    return ans;

}
/*Solution analysis:
 Time complexsity: O(log2(n)) [REASON: SINCE WE KEEP ON DIVIDING BY 2 WE GET LOG2(N)]
 Auxillary space complexsity: O(1)
 */
//==============================================================================
 //OPTIMAL SOLUTION
 int countSetBit (int n)
{
    int ans=0;
    while(n)
    {
        ans++;
        n=(n&(n-1));  
    }
    return ans;

}
// Explanation:
//     Same as we did in sum DAY12_1 for the sake of counting the total number of set bits 
// DRY RUN:
//     N=25
//     in binary: 11001
// in first loop
//     11001
//    &11000
//     -----
//     11000   ANS=1;
// in SECOND loop
//     11000
//    &10111
//     -----
//     10000 ANS=2;
// in THIRD loop
//     10000
//     01111
//     -----
//     00000 ANS=3;
// NOW N=0 so the conditon in while loop fails and the ans is returned 

/*Solution analysis:
 Time complexsity: O(log2(n)) [actually less than the brute force because it runs for only the number of set bits in it where as the previous solution runs for all the bits untill we find the set bit in MSB]
 Auxillary space complexsity: O(1)
 */
//==============================================================================
// Most optimal solution (with some flaws)
//  the most optimal solution lies in LOOK UP table methord (similary to maping) its very effective 
//  it gives us answer in O(1) time but setting up the table will take extra time 
int table[256];
void initializeLookUpTable() //table is filled based on Brains's algorithm working
{
    table[0]=0;
    for(int i=1;i<256;i++)
        table[i]=(i&1) + table[i/2];
}
int CountSetBit(int n)
{
    initializeLookUpTable();
    int result=0;
    result+=table[n & 0xFF];
    n=n>>8;
    result+=table[n & 0xFF];
    n=n>>8;
    result+=table[n & 0xFF];
    n=n>>8;
    result+=table[n & 0xFF];
    return result;
}
// Explanation:
// integer is 4 byte datatype 
// we check for number of set bits in each of the bytes seperately and add it to result
//===========================================================
//Availaitily of build-in-function
 int countSetBit (int n)
{
   int ans=__builtin_popcount(n);
   return ans;
}
//Important: use this build in function in online assesments only if counting set bits is a part of the solution and permitted
//to use this function we need to include "#include<bits/stdc++.h>" in importing section