/*

Problem link:  https://leetcode.com/problems/sort-colors/




Problem statement:
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, 
with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue,
respectively.

You must solve this problem without using the library's sort function.

 
Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant 
extra space?

*/

//while using leetcode consider that the inputs were already guven only complete 
//function to sort 

class Solution {
public:
   
    void sortColors(vector<int>& nums) {
        int *low=&nums[0];				//low pointer
        int *mid=&nums[0];				//mid pointer
        int *high=&nums[nums.size()-1];   //initialise high pointer to last element of array



while(mid<=high)			//compare the low pointer and high pointer value
{
	switch(*mid)			//equivalent of using checking the value of each data using if statement
	{
		
		case 0:
			{
				//if the element is 0 swap with low pointer value and increase low & mid pointer
				swap(mid,low);
				low++;
				mid++;
				break;
			}
		case 1:
			{
				//if it is 1 go to  next element
				mid++;
				break;
			}
		case 2:
			{
				//if the element is 0 swap with high pointer value and decrease high pointer
				swap(mid,high);
				high--;
				break;
			}
			
	}
	
}


        
    }
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;

}
};






/*
Runtime: 3 ms, 
Memory Usage: 8.3 MB, 
*/



