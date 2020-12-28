/*
 * @lc app=leetcode.cn id=85 lang=c
 *
 * [85] 最大矩形
 */

// @lc code=start


// int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
//     int row = matrixSize;
//     if(row == 0)
//         return 0;
//     int col = matrixColSize[0];
//     if(col == 0)
//         return 0;
//     int width[row][col], area[row][col], maxArea = 0, min;
//     memset(area, 0, sizeof(area));
//     for (int i = 0; i < row; i++){
//         for (int j = 0; j < col; j++){
//             width[i][j] = matrix[i][j] == '1' ? (j == 0 ? 1 : width[i][j - 1] + 1) : 0;
//             // if(width[i][j] == 0)
//             //     continue;
//             for (int k = 1; k <= i; k++){
//                 if(area[i - k + 1][j] == 0){
//                     min = fmin(min, width[i - k + 1]);
//                     area[i - k + 1][j] = width[i - k + 1][j] * k;
//                 }
//                 maxArea = fmax(maxArea, area[i - k + 1][j]);
//             }
//         }
//     }
//     return maxArea;
// }
// @lc code=end

