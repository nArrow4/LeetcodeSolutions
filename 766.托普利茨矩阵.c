/*
 * @lc app=leetcode.cn id=766 lang=c
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
#include<stdlib.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize){
    //printf("%d %d", matrixColSize[0], matrixSize);
    int *preCol;
    preCol = (int *)malloc(sizeof(int) * matrixColSize[0]);
    //printf("%d %d", sizeof(preCol), sizeof(int) * matrixColSize[0]);
    memcpy(preCol, matrix[0], sizeof(int) * matrixColSize[0]);
    // for (int i = 0; i < matrixColSize[0]; i++){
    // //    preCol[i] = matrix[0][i];
    //     printf("%d ", preCol[i]);
    // }
    for (int i = 1; i < matrixSize; i++){
        for (int j = 0; j < matrixColSize[i] - 1; j++){
            //printf("%d %d ", matrix[i][j + 1], preCol[j]);
            if(matrix[i][j + 1] != preCol[j]){
                //printf("%d %d ", matrix[i][j + 1], preCol[j]);
                return false;
            }
        }
        memcpy(preCol, matrix[i], sizeof(int)*matrixColSize[i]);
    }

    return true;
}


// @lc code=end

