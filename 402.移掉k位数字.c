/*
 * @lc app=leetcode.cn id=402 lang=c
 *
 * [402] 移掉K位数字
 */

// @lc code=start


char * removeKdigits(char * num, int k){
    char *stack;
    int len = strlen(num) - k, top = -1, m = 0;
    stack = (char *)malloc(sizeof(char) * strlen(num));
    stack[len] = '\0';
    while(k-- && top != len - 1){
        // 找到递减序列
        for (int i = 0; i < strlen(num) - 1; i++){
            // 如果是递减的保存下一位
            while(k && num[i] > num[i + 1]){
                // 找到递减的序列
                stack[top] = num[i + 1];
                i = i + 1;
                k--;
            }
            // 如果是递增的，保存当前位
            if(num[i] <= num[i+1]){
                stack[++top] = num[i];
            }
        }
        stack[++top] = num[strlen(num) - 1];
        while(k--){
            top--;
        }
    }
    stack[++top] = '\0';
    return stack;
}


// @lc code=end

