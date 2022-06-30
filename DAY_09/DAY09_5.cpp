// DAY 09
// QUESTION NO 5:Palindrome Partitioning
// Question Explanation:You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.
//Note: A palindrome string is a string that reads the same backward as forward.
// Input: s = “aab”
// Output: [ ["a","a","b"], ["aa","b"] ]	
// Explanation: The first  answer is generated by  making three partitions. The second answer is generated by making two partitions.
//Optimal solution
//code
    bool isPalindrome(string s,int start,int end) //this function check wheather the given string is palindrome or not
    {
        while(start<=end)
        {
            if(s[start]!=s[end]) //compare first and last element
            {
                return false; //if they are true return fasle
            }
                start++;
                end--;
        }
        return true;
    }
    void fun(int index,string s,vector<vector<string>>& result,vector<string>& ds)
    {
        if(index==s.length()) //if we have reached to the end then we have Partitioned the string
        {
            result.push_back(ds);//push it to the result
            return;
        }
        for(int i=index;i<s.length();i++) 
        {
            if(isPalindrome(s,index,i)) //checks if the choosen partition is palindrome or not .If palindrome we pushit to the ds and check for the next patition 
            {
                ds.push_back(s.substr(index,i-index+1));  //substr(start_index,length)
                fun(i+1,s,result,ds);//to check for next partition
                ds.pop_back(); //remove the last element and again go over
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> result;
        vector<string> ds;
        fun(0,s,result,ds);//this function will do all the required work
        return result;
    }
/*Solution analysis:
 Time complexsity: O((2^n)*k*n) {O(2^n) to generate every substring and O(n)  to check if the substring generated is a palindrome. O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.}
 Auxillary space complexsity: O(N)  [O(N), where N is the length of the string s. This space will be used to store the recursion stack.]
//  *
//Problem link: https://leetcode.com/problems/palindrome-partitioning/
//Blog about substr() function : https://www.geeksforgeeks.org/substring-in-cpp/
