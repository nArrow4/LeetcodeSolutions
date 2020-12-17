/*
 * @lc app=leetcode.cn id=130 lang=c
 *
 * [130] 被围绕的区域
 */

// @lc code=start


/**方法一：dfs
 * 思路：找与边界相连的O
 * T:O(n*m)
 * S:O(n*m)
 */
void fillBoard(char** board, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(board[i][j] == 'A')
                board[i][j] = 'O';
            else
                board[i][j] = 'X';
        }
    }
    return;
}

void dfs(char** board, int row, int col, int r, int c){
    board[r][c] = 'A';
    if(r+1<row && board[r+1][c] == 'O')
        dfs(board, row, col, r + 1, c);
    if(c+1<col && board[r][c+1] == 'O')
        dfs(board, row, col, r, c + 1);
    if(r-1>-1 && board[r-1][c] == 'O')
        dfs(board, row, col, r  - 1, c);
    if(c-1>-1 && board[r][c-1] == 'O')
        dfs(board, row, col, r , c - 1);
}

void solve(char** board, int boardSize, int* boardColSize){
    if(boardSize == 0)
        return NULL;
    int row = boardSize;
    int col = boardColSize[0];
    for (int i = 0; i < col; i++){
        if (board[0][i] == 'O')
            dfs(board, row, col, 0, i);
        if (board[row-1][i] == 'O')
            dfs(board, row, col, row - 1, i);
    }
    for (int j = 0; j < row; j++){
        if (board[j][0] == 'O')
            dfs(board, row, col, j, 0);
        if (board[j][col-1] == 'O')
            dfs(board, row, col, j, col - 1);
    }
    fillBoard(board, row, col);
    return;
}
// @lc code=end

