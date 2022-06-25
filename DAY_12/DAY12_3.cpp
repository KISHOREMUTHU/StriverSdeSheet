// DAY 12 
// QUESTION NO 3:  Division without using division operator(/)
// Question Explanation:
// YOU WILL BE PROVIDED WITH TWO NUMBERS THE dividend AND THE DIVISOR 
// FOR EXAMPLE :
// dividend=10
// divisor=3
// WE NEED TO FIND dividend/divisor i.e> 10/3 =3 (JUST INTEGER DIVISION IS ENOUGH NO NEED TO PROVIDE 3.333)
//  BRUTE FORCE APPROACH
//we keep on subracting the divisor from the dividend and keep the track of count 
int division(int dividend,int divisor)
{
    ans=0;
    while(dividend>=divisor)
    {
        ans++;
        dividend=dividend-divisor; //we just keep on subracting the divisor from the dividend  
    }
    return ans;
}
//the above solution doesn't work when the number is a negative number
/*Solution analysis:
 Time complexsity: O(dividend) 
 Auxillary space complexsity: O(1)
 */
//==============================================================================
//Optial approach
int division(int dividend,int divisor)
{
    if (dividend == INT_MIN && divisor == -1)//edge case : because numbers in int lies from 2^31 to 2^31 - 1
        {
            return INT_MAX;
        }
        long PositiveDividend = labs(dividend);
        long PositiveDivisor = labs(divisor);
        long  ans = 0;
        short int sign = (dividend > 0) ^(divisor > 0)? -1 : 1; //using Xor Gate to check the sign of result
        //ALTER FOR SIGN CHECKINH
        // int sign=1;
        // if(dividend<0)
        //     sign=sign*-1;
        // if(divisor<0)
        //     sign=sign*-1;
        while (PositiveDividend >= PositiveDivisor) 
        {
            long temp = PositiveDivisor, m = 1;
            while (temp << 1 <= PositiveDividend)
            {
                temp <<= 1;
                m <<= 1;
            }
            PositiveDividend -= temp;
            ans += m;
        }
        return sign * ans; 
}
//Explanation :
consider 58/5
dividend = (quotient) * divisor + remainder      
	5 << 0 = 5               // less than dividend
	5 << 1 = 5*2 = 10        // less than dividend
	5 << 2 = 5*2*2 = 20      // less than dividend
	5 << 3 = 5*2*2*2 = 40    // less than dividend
	5 << 4 = 5*2*2*2*2 = 80  // (stop and consider the previous value as the result is greater than dividend
then
	58 - (2^3 * 5)  =  (something * 5) + rem
	58 - (8 * 5) = something * 5 + rem
	58 - 40 = something * 5 + rem
	18 = something * 5 + rem
again repeate the procedure
    5 << 0 = 5           // less than dividend
	5 << 1 = 5*2 = 10    // less than dividend
	5 << 2 = 5*2*2 = 20  // (stop and consider the previous value as the result is greater than dividend
then
    18-(2^1 * 5) = 8
again repeate the procedure 
    5 << 0 = 5           // less than dividend
	5 << 1 = 5*2 = 10    // (stop and consider the previous value as the result is greater than dividend
then 
    8-(2^0 * 5)= 3 < 5  //thus now we can return the result

58 = (2^3 + 2^1 + 2^0) * 5 + 3
dividend = (quotient) * divisor + remainder     
answer= 2^3 + 2^1 + 2^0; //quotient 

//The above solution works fine and handles all the edge case 
/*Solution analysis:
 Time complexsity: O(log(dividend)) 
 Auxillary space complexsity: O(1)
 */


//  leetcode: https://leetcode.com/problems/divide-two-integers/ (Difficulty:Medium)
