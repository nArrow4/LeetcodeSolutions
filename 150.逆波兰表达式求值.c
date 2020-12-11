/*
 * @lc app=leetcode.cn id=150 lang=c
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include<string.h>
/**
 * @brief: 求解逆波兰表达式
 * @param {char**} 后缀式逆波兰表达式
 * @param {int} 逆波兰表达式的长度
 * @return {int} 逆波兰表达式的值
 */
int evalRPN(char ** tokens, int tokensSize){
    int *stack, top = -1, leftop, rightop;
    stack = (int *)malloc(sizeof(int) * (tokensSize + 1) / 2);
    for (int i = 0; i < tokensSize; i++){
        if(strcmp(tokens[i], "+") == 0){
            //加法运算
            rightop = stack[top--];
            leftop = stack[top--];
            stack[++top] = rightop + leftop;
            // printf("%d", stack[top]);
        }
        else if(strcmp(tokens[i], "-") == 0){
            //减法运算
            rightop = stack[top--];
            leftop = stack[top--];
            stack[++top] = leftop - rightop;
            // printf("%d", stack[top]);
        }
        else if(strcmp(tokens[i], "*") == 0){
            //乘法运算
            rightop = stack[top--];
            leftop = stack[top--];
            stack[++top] = rightop * leftop;
            // printf("%d", stack[top]);
        }
        else if(strcmp(tokens[i], "/") == 0){
            //除法运算
            rightop = stack[top--];
            leftop = stack[top--];
            stack[++top] = leftop / rightop;
            // printf("%d", stack[top]);
        }
        else{
            stack[++top] = atoi(tokens[i]);
            // printf("%d", stack[top]);
        }
    }
    return stack[top];
}


// @lc code=end

