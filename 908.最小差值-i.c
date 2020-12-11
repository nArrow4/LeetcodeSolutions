/*
 * @lc app=leetcode.cn id=908 lang=c
 *
 * [908] 最小差值 I
 */

// @lc code=start
#include<limits.h>

int smallestRangeI(int* A, int ASize, int K){
    int min = INT_MAX, max = INT_MIN, res;
    for (int i = 0; i < ASize; i++){
        if(A[i] < min){
            min = A[i];
        }
        if(A[i] > max){
            max = A[i];
        }
    }
    res = max - min - 2 * K;
    return res > 0 ? res : 0;
}


// @lc code=end

