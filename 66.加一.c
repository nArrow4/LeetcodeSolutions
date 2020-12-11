/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (43.62%)
 * Likes:    445
 * Dislikes: 0
 * Total Accepted:    135.6K
 * Total Submissions: 310.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    *returnSize = digitsSize;
    if(*(digits+digitsSize-1) < 9){
        *(digits + digitsSize - 1) += 1;
        return digits;
    }
    else{
        int sum = 1;
        for (int i = digitsSize - 1; i >= 0; i--){
            if(sum == 0)
                return digits;
            else{
                if(i == 0 && digits[i] == 9){
                    *digits = 0;
                    int *res = (int *)malloc(sizeof(int) * (digitsSize + 10));
                    *res = 1;
                    for (int i = 0; i < digitsSize; i++){
                        res[i + 1] = digits[i];
                    }
                    *returnSize = digitsSize + 1;
                    return res;
                }
                else{
                    digits[i] = digits[i] + sum;
                    if(digits[i] == 10){
                        sum = 1;
                        digits[i] = 0;
                    }
                    else
                        return digits;
                }
            }
        }
    }
    return digits;
}
/*
感觉写的很麻烦一直if if
*/
/*解一
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]<9)
        {
            
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
        digits[i]=0;
    }
    int* result=(int*)malloc(sizeof(int)*(digitsSize+1));
    result[0]=1;
    for(int i=1;i<(digitsSize+1);i++)
    {
        result[i]=0;
    }
    *returnSize=digitsSize+1;
    return result;
}
*/
/*解二
int* plusOne(int* digits, int digitsSize, int* returnSize){
    for(int i=digitsSize-1; i>-1; --i){
        digits[i] = ++digits[i] % 10; // 加一后取个位
        if(digits[i] != 0) break;// 无进位，循环退出
    }
    *returnSize = digitsSize + (digits[0] == 0); // 首位为0说明最高位进位，长度+1
    int *res = (int *)malloc(*returnSize * sizeof(int));
    res[0] = 1; // 假设最高位为1
    memcpy(res + (digits[0] == 0), digits, digitsSize * sizeof(int)); // 复制digits到res的后digitsSize位中
    return res;
}
*/

// @lc code=end

