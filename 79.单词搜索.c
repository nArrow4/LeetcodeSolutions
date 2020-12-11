/*
 * @lc app=leetcode.cn id=79 lang=c
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    48.8K
 * Total Submissions: 118.8K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start

bool _exist(char **board, int row, int col, char *word, int y, int x)
{
    if (*word == '\0')
        return true;
    if (y < 0 || y >= row || x < 0 || x >= col || *word != board[y][x])
        return false;
    board[y][x] = '\0';
    bool result = _exist(board, row, col, word + 1, y, x - 1) ||
                  _exist(board, row, col, word + 1, y - 1, x) ||
                  _exist(board, row, col, word + 1, y, x + 1) ||
                  _exist(board, row, col, word + 1, y + 1, x);
    board[y][x] = *word;
    return result;
}
bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    for (int y = 0; y < boardSize; y++)
        for (int x = 0; x < boardColSize[0]; x++)
            if (board[y][x] == word[0] && _exist(board, boardSize, boardColSize[0], word, y, x))
                return true;
    return false;
}
/*
这个自己写的，感觉一模一样，但就有个过不了
bool backTracking(char**board, int row, int col, char* word, int y, int x){
    if(*word == '\0')
        return true;
    if(y<0 || x<0 || y>=row || x>=col || *word != board[y][x])
        return false;
    board[y][x] = '\0';
    bool result = backTracking(board, row, col, word + 1, y, x - 1) ||
                  backTracking(board, row, col, word + 1, y - 1, x) ||
                  backTracking(board, row, col, word + 1, y, x + 1) ||
                  backTracking(board, row, col, word + 1, y + 1, x);
    board[y][x] = *word;
    return result;
}

bool exist(char** board, int boardSize, int* boardColSize, char *word){
    int x = 0, y = 0;
    for (; y < boardSize; y++){
        for (; x < boardColSize[0]; x++){
            if(word[0] == board[y][x] && backTracking(board, boardSize, boardColSize[0], word, y, x)){
                return true;
            }
        }
    }
    return false;
}
*/
// @lc code=end
