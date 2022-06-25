// DAY 12 
// QUESTION NO 6: Find square of a number without using mul or div operator
//  BRUTE FORCE APPROACH
//  Explanation:
// Sum of n odd numbers:=n^2
// Proof:
// suppose we take following n numbers-4

// =1+3+5+7
// =1+(2+1)+(3+2)+(4+3) we can write again as..
// =[1+2+3+4] +[1+2+3]
// =[Sum of n natural numbers]+[Sum of (n-1) natural numbers]
// =n(n+1)/2 + (n-1) [(n-1)+1]/2 By solving it,we find
// =[n^2+n]/2+[n^2-n]/2 again we can simplify as
// =(2n^2)/2
// =n^2

int SquareOfNumber(int n)
{
    n=abs(n);
    int ans=0;
    int x=1;
    for(int i=0;i<n;i++)
    {
        ans=ans+x;
        x=x+2;
    }
    return ans;
}
//alter
int SquareOfNumber(int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
        ans=ans+n;
    return abs(ans);
}
/*Solution analysis:
 Time complexsity: O(n) 
 Auxillary space complexsity: O(1)
 */

// ====================================
// Optimal approach:
//explanation:
// consider: n^2=n*n 
// let n=5
// 5 in binary 00101
// 5^2= (5)*(00101B)
//    =(5)*(2^0+2^2)
//    =((5*(2^0))+ (5*(2^2)))
// (since here we cant use mul operation we perform left shift(since mul by two powers))
//    =5<<0 + 5<<3
int SquareOfNumber(int n)
{
  n = abs(n);
  int temp_n = n;
  int res = 0;
  int pos = 0;
  while(temp_n)
   {
    if(temp_n & 1)
    {
      res += (n<<pos);
    }
    pos++;
    temp_n >>= 1;
   } 
  cout << res << endl;
}

/*Solution analysis:
 Time complexsity: O(log(n)) 
 Auxillary space complexsity: O(1)
 */