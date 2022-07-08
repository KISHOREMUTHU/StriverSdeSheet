// DAY 10
// QUESTION NO : 10 Rat in Maize
// Question Explanation: Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N – 1, N – 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.
// Note: In a path, no cell can be visited more than one time.
// Print the answer in lexicographical(sorted) order

//Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//         {1, 1, 0, 1}, 
//         {1, 1, 0, 0},
//         {0, 1, 1, 1}}

// Output: DDRDRR DRDDRR

//Refer this blog: https://takeuforward.org/data-structure/rat-in-a-maze/ 
//for understanding the question

//Approach with length code:
//code:
void solve(int row, int col, vector < vector < int >> & a, int n, vector < string > & ans, string move,vector < vector < int >> & vis)
 {
    if (row == n - 1 && col == n - 1) //if we have reached the end add it to the answer
    {
      ans.push_back(move);
      return;
    }
    //we check in the order D,L,R,U (lexiographical)
    //so we no need to sort it after getting it.
    // downward
    if (row + 1 < n && !vis[row + 1][col] && a[row + 1][col] == 1)
    {
      vis[row][col] = 1;
      solve(row + 1, col, a, n, ans, move + 'D', vis);
      vis[row][col] = 0;
    }

    // left
    if (col - 1 >= 0 && !vis[row][col - 1] && a[row][col - 1] == 1) 
    {
      vis[row][col] = 1;
      solve(row, col - 1, a, n, ans, move + 'L', vis);
      vis[row][col] = 0;
    }

    // right 
    if (col + 1 < n && !vis[row][col + 1] && a[row][col + 1] == 1) 
    {
      vis[row][col] = 1;
      solve(row, col + 1, a, n, ans, move + 'R', vis);
      vis[row][col] = 0;
    }

    // upward
    if (row - 1 >= 0 && !vis[row - 1][col] && a[row - 1][col] == 1) 
    {
      vis[row][col] = 1;
      solve(row - 1, col, a, n, ans, move + 'U', vis);
      vis[row][col] = 0;
    }

  }
    vector < string > findPath(vector < vector < int >> & m, int n) 
    {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) //if the first element itself zero then we cant move anywhere 
        solve(0, 0, m, n, ans, "", vis);
      return ans;
    }


/*Solution analysis:
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space) if we dont consider the recursion tree here means then its O(1).. 
 */
// ===================================================================

//Same procedure with good code Quality
//code:
void solve(int row, int col, vector < vector < int >> & a, int n, vector < string > & ans, string move,vector < vector < int >> & vis, int di[], int dj[])
{
    if (row == n - 1 && col == n - 1) 
    {
      ans.push_back(move);
      return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++) {
      int nexti = row + di[ind];
      int nextj = col + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        vis[row][col] = 1;
        solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
        vis[row][col] = 0;
      }
    }

}
    vector < string > findPath(vector < vector < int >> & m, int n) {
      vector < string > ans;
      vector < vector < int >> vis(n, vector < int > (n, 0));
      `          //{D,L,R, U}
      int di[] = {1,0,0,-1}; //there are the patterns for DLRU in Row
      int dj[] = {0,-1,1,0}; //these are the patters for DLRU in Columb
      if (m[0][0] == 1) //if the first element itself zero then we cant move anywhere 
        solve(0, 0, m, n, ans, "", vis, di, dj);
      return ans;
    }
/*Solution analysis:
Time Complexity: O(4^(m*n)), because on every cell we need to try 4 different directions.
Space Complexity:  O(m*n) ,Maximum Depth of the recursion tree(auxiliary space) if we dont consider the recursion tree here means then its O(1). 
 */
//Problem Link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1