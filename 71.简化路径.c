/*
 * @lc app=leetcode.cn id=71 lang=c
 *
 * [71] 简化路径
 */

// @lc code=start
#include<string.h>

char * simplifyPath(char * path){
    int top = -1;
    char **stack, *res, *s = path, *tail;
    stack = (char **)malloc(sizeof(char *));
    res = (char *)malloc(sizeof(char));
    if(!res || !stack)
        return NULL;
    // 将path按/分割入栈，处理.和..
    while(*s != '\0'){
        // 分割
        if(*s == '/'){
            tail = s + 1;
            while(*tail != '/' && *tail != '\0'){
                tail++;
            }
            if(tail - s == 1)
                break;
            printf("%d", tail - s);
            stack[++top] = (char *)malloc(sizeof(char) * (tail - s));
            stack[top] = s + 1;
            stack[top][tail - s - 1] = '\0';
        }
        // else{
        //     while(*tail != '/' && *tail != '\0'){
        //         tail++;
        //     }
        // }
        s = tail;
    }
    *res = '/';
    for (int i = 0; i < top; i++){
        
    }
    return res;
}


// @lc code=end

