// DAY 09
// QUESTION NO 6: K-th permutation Sequence
// Question Explanation:Given N and K, where N is the sequence of numbers from 1 to N([1,2,3.. N]) find the Kth permutation sequence.
// Input: N = 3, K = 3
 
// Output:"213"

// Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.
//Brute Force
//Create all posible permutitation using recusion store it in a datastructure sort it and return the Kth permutaion 
//code:
    //function to generate all possible permutations of a string
    void solve(string & s, int index, vector < string > & res)//same pattern as we did in previous sums
     {
      if (index == s.size()) {
        res.push_back(s);
        return;
      }
      for (int i = index; i < s.size(); i++) 
      {
        swap(s[i], s[index]); //swap them
        solve(s, index + 1, res);
        swap(s[i], s[index]); //again bring them back to old position
      }
    }

  string getPermutation(int n, int k)
   {
    string s;
    vector < string > res;
    for (int i = 1; i <= n; i++)
    {
      s.push_back(i + '0');//to store it as string
    }
    solve(s, 0, res);
    //sort the generated permutations
    sort(res.begin(), res.end());
    return res[k-1];
  }
  /*Solution analysis:
 Time complexsity: O(N! * (N)) + O(N!Log(N!)) {N!Log(N!) for sorting and N! for creating all posible permutation and N for sorting them into data structure}
 Auxillary space complexsity: ON)  [O(N), where N is the length of the string s. This space will be used to store the recursion stack.]
//  */
//===========================================================================================

//Optimal Approach(This is a non recursive solution)
//code

string getPermutation(int n, int k)
    {
        string ans="";
        vector<int> number;
        for(int i=1;i<=n;i++)
            number.push_back(i);
        int fact=1;
        for(int i=1;i<n;i++)
            fact*=i;
        k=k-1;//we are considering 0 based indexing
        while(1)
        {
            ans=ans+to_string(number[k/fact]);//add the element to answer
            number.erase(number.begin()+(k/fact)); //remove the element from the vector
            if(number.size()==0)//if all the elements are removed from the vector then break the loop
                break;
            k=k%fact; 
            fact=fact/number.size();
        }
        return ans;
        
    }
/*Solution analysis:
 Time complexsity: O(N^2) Reason:{We are placing N numbers in N positions. This will take O(N) time. For every number, we are reducing the search space by removing the element already placed in the previous step. This takes another O(N) time.}
 Auxillary space complexsity: O(N) {for the vector number}
//  *
//Problem link: https://leetcode.com/problems/permutation-sequence/