// DAY 10
// QUESTION NO 2: N Queens
// Question Explanation: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. 
//Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.
// Examples:

// Input: n = 4

// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown below

//Refer this image for detailed understanding : https://www.shorturl.at/AEJ34 
//(not the optimal but without extra space)
//Code:
bool isSafe1(int row, int col, vector < string > board, int n)  //check weather we can place the element in that position or not (no need to care for left side movement since we haven't placed any in them)
{
      
      int duprow = row;
      int dupcol = col;
    // checks upper diagonal element
      while (row >= 0 && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      //check for horizontal case
      while (col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      //checks for lower diagonal
      while (row < n && col >= 0) {
        if (board[row][col] == 'Q')
          return false;
        row++;
        col--;
      }
      return true; //if all conditons are met then we can place the queen there.
    }
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n)
    {
      if (col == n) //all have been filled then place it in the answer
      {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) 
      {
        if (isSafe1(row, col, board, n)) //check can we place it there
        {
          board[row][col] = 'Q';
          solve(col + 1, board, ans, n);
          board[row][col] = '.'; //check other place in the same columb
        }
      }
    }
    vector < vector < string >> solveNQueens(int n)
    {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++)
      {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }


/*Solution analysis:
 Time complexsity: O(N! * N) { Exponential in nature, since we are trying out all ways. To be precise it goes as O}
 Auxillary space complexsity: O(1) {We are not including the space we used here and not considering the space we use for recursion} 
 */
// ===================================================================
//optimal approach but takes extra space
//here we use mapping and avoid checking for each and every columb
//code:
  void fun(vector<bool> &top,vector<bool> &bottom,vector<bool> &mid,int col,int n,vector<vector<string>> &ans,vector<string>&ds)
    {
           if(col==n)
           {
               ans.push_back(ds);
               return;
           }
            for(int row=0;row<n;row++)
            {
                if(mid[row]==0 and top[row+col]==0 and bottom[n-1+row-col]==0)
                {
                    ds[row][col]='Q';
                    mid[row]=1;
                    top[row+col]=1;
                    bottom[n-1+row-col]=1;
                    fun(top,bottom,mid,col+1,n,ans,ds);
                    ds[row][col]='.';
                    mid[row]=0;
                    top[row+col]=0;
                    bottom[n-1+row-col]=0;                  
                    
                }
            }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string>ans1;
        string s(n,'.');
        vector<bool> top(2*n-1,0);
        vector<bool> bottom(2*n-1,0);
        vector<bool> mid(n,0);
        
        for(int i=0;i<n;i++)
            ans1.push_back(s);
        fun(top,bottom,mid,0,n,ans,ans1);
        return ans;
    }
/*Solution analysis:
 Time complexsity: O(N! * N) { Exponential in nature, since we are trying out all ways. To be precise it goes as O}
 Auxillary space complexsity: O(N) {space we used for mapping the space we used for recursion is not considered}
 */
// ===================================================================
//Question link: https://leetcode.com/problems/n-queens/