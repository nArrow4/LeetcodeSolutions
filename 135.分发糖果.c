/*
 * @lc app=leetcode.cn id=135 lang=c
 *
 * [135] 分发糖果
 */

// @lc code=start
#include<string.h>
int candy(int* ratings, int ratingsSize){
    int res = 0, candys[ratingsSize];
    memset(candys, 0, sizeof(int)*ratingsSize);
    candys[0] = 1;
    for(int i=1;i<ratingsSize;i++){     //正向
        if(ratings[i]>ratings[i-1]){
            candys[i] = candys[i-1]+1;
        }
        else candys[i]=1;
    }
    for(int i=ratingsSize-2;i>=0;i--){  //反向
        if(ratings[i]>ratings[i+1]){
            candys[i] = fmax(candys[i+1]+1, candys[i]);
        }
        res += candys[i];
    }
    res += candys[ratingsSize - 1];
    return res;
}


// @lc code=end

