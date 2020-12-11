/*
 * @lc app=leetcode.cn id=224 lang=c
 *
 * [224] 基本计算器
 */

// @lc code=start
#include<string.h>

typedef struct{
    int top;
    int *stack;
} Stack;

int calculate(char * s){
    // Stack op, res;
    // int len = strlen(s);
    // op.stack = (int *)malloc(sizeof(int) * (len) / 2);
    // op.top = -1;
    // res.stack = (int *)malloc(sizeof(int) * (len));
    // res.top = -1;
    // // 先将中缀表达式转换为后缀表达式
    // for (int i = 0; i < len; i++){
    //     if(s[i] == ' ')
    //         continue;
    //     if(s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
    //         // 检测到算符
    //         if(s[i] != ')')
    //             // 检测到一个完整的括号，表达式反向入栈（可以顺便计算）
    //             while(op.top != -1 && op.stack[op.top--] != '('){
    //                 res.stack[++res.top] = op.stack[op.top];
    //             }
    //         else{
    //             // 直接入栈
    //             op.stack[++op.top] = s[i];
    //         }
    //     }
    //     else{
    //         // 检测到数字
    //         res.stack[++res.top] = s[i] - '0';
    //     }
    // }
    // for (int i = 0; i < len; i++){
    //     printf("%d ", res.stack[i]);
    // }
    // // 计算后缀表达式

    return 0;
}


// @lc code=end

