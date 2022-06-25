// DAY 12 
// QUESTION NO 5:Find MSB of the number in O(1)  
//  BRUTE FORCE APPROACH
//Explanation:
if the number given is 10 its binary number is 0001010  the left most set bit is four places away from rigth most end its value is 2^4= 16 we need to return it
//solution:
int MSBNumber(int n)
{
    if (n == 0)
        return 0;
 
    int msb = 0;
    n = n / 2;
    while (n != 0) {
        n = n / 2;
        msb++;
    }
 
    return (1 << msb);//we can also return 2^msb both will provide same answer
}
 /*Solution analysis:
 Time complexsity: O(log2(n)) [REASON: SINCE WE KEEP ON DIVIDING BY 2 WE GET LOG2(N)]
 Auxillary space complexsity: O(1)
 */
 //but we are asked to provide with a O(1) solution
// =================================================
//Optimal Approach
int MSBNumber(int n)
{
    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;
 
    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
 
    // The naive approach would increment n by 1,
    // so only the MSB+1 bit will be set,
    // So now n theoretically becomes 1000000000.
    // All the would remain is a single bit right shift:
      n = n + 1;
      return (n >> 1);
}
 /*Solution analysis:
 Time complexsity: O(1)
 Auxillary space complexsity: O(1)
 */