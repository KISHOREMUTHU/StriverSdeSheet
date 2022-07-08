// DAY 10
// QUESTION NO 3: Sudoku Solver
// Question Explanation: Given a 9×9 incomplete sudoku, solve it such that it becomes valid sudoku.
//Approach:
// 1. All the rows should be filled with numbers(1 – 9) exactly once.
// 2. All the columns should be filled with numbers(1 – 9) exactly once.
// 3. Each 3×3 submatrix should be filled with numbers(1 – 9) exactly once.

//code:
 bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char k = '1'; k <= '9'; k++) //check from 1 - 9
                {
                    if (isValid(board, i, j, k)) //if K can fit then fit it in the board 
                    {
                        board[i][j] = k;

                        if (solve(board) == true)//here they ask for only one solution so after finding the first solution we can return it 
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }
    return true;
}

bool isValid(vector<vector<char>> &board, int row, int col, char k)
//this function checks wheather the optained suduko is valid or not if we place the element k in the position [row][col]
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == k)
            return false;

        if (board[i][col] == k)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
            return false;
    }
    return true;
}
void solveSudoku(vector<vector<char>>& board)
{
    solve(board);   
}


/*Solution analysis:
Time Complexity: O(9^(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity: O(1), {here wwe are not considering the space we use for recusions stack}. 
 */
// ===================================================================

//Problem Link: https://leetcode.com/problems/sudoku-solver/