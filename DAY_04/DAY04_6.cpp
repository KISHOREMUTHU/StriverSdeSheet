// DAY 4
// QUESTION NO : 6
// Question Explanation: Length of Longest Substring without any Repeating Character
// Given a String, find the length of longest substring without any repeating character.
// Input: s = ”abcabcbb”
// Output: 3
// Explanation: The answer is abc with length of 3.
//Brute force: 
//we directly iterate for all possible sub array and check if they are repeating or not using a set
//code:
int solve(string str) {

  if(str.size()==0)
      return 0;
  int maxans = 0;
  for (int i = 0; i < str.length(); i++) 
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) 
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i); //we consider its size (j-i) excluding the current index
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}

/*Solution analysis:
 Time complexsity: O(n^2)//for two loops 
 Auxillary space complexsity: O(n)  //for the datastructure set
 */
// ===================================================================
//Methord 2:
//Optimal:
//code:
 int lengthOfLongestSubstring(string s) 
 {
        int n=s.length();
        int l=0,r=0;
        int len=0;
        vector<int> map(256,-1); //we can have 256 characters (alphebets symbols etc)
        while(r<n)
        {
            if(map[s[r]]!=-1) 
                l=max(l,map[s[r]]+1);//we find the last occurancec of the element
            map[s[r]]=r;
            len=max(r-l+1,len);
            r++;
        }
        return len;
    }
/*Solution analysis:
 Time complexsity: O(n) //we get answer in single traversal
 Auxillary space complexsity: O(n)  //Consider we use map here then O(n) here its O(256)=O(1)
 */
// ===================================================================
//Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/