// DAY 12 
// QUESTION NO 4: Power set using bitwise
//Question explanation:
// Example 1:
// Input: str = "abc"
// Output: a ab abc ac b bc c
// Explanation: Printing all the 7 subsequence for the string "abc".
// Example 2:
// Input: str = "aa"
// Output: a a aa 
// Explanation: Printing all the 3 subsequences for the string "aa"
// ==============
//Solution:
vector<string> AllPossibleStrings(string s) {
	int n = s.length();//gives the length of the string
	vector<string>ans;
	for (int num = 0; num < (1 << n); num++) {
		string sub = "";
		for (int i = 0; i < n; i++) {
			if (num & (1 << i))//check if the ith bit is set or not
            {
				sub += s[i];
			}
		}
		if (sub.length() > 0) {
			ans.push_back(sub);//push the obtained combination into the ans vector
		}
	}
	sort(ans.begin(), ans.end());//just for the sake of submiting in leetcode
	return ans;
}
 /*Solution analysis:
 Time complexsity:  O(2^n * n) [REASON: O(2^n) for the outer for loop and O(n) for the inner for loop.]
 Auxillary space complexsity: O(1) 
 */



 //Note: The most optimal sollution lies in recursion we will see it later