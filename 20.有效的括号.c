/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start

/*
运用了栈的思想（先进后出）
先让左括号入栈，在判断到右括号时出栈
右括号的判断时，注意ASCII码的关系
*/
bool isValid(char * s){
    int len, top = -1;
    len = strlen(s);
    if(len==0)
        return true;
    char *stack;
    stack = (char *)malloc(sizeof(char) * len);
    //printf("%d %d %d %d %d %d", '(', ')', '[', ']', '{', '}');
    for (char *p = s; *p; p++){
        if(*p=='(' || *p=='{' || *p=='[')
            stack[++top] = *p;
        else if(top == -1)
            return false;
        else{
            //'('==')'-1, '['==']'-2, '{'=='}'-2
            if(stack[top]==*p-1 || stack[top]==*p-2)
                top--;
            else
                return false;
        }
    }
    if(top==-1)
        return true;
    return false;
}
// @lc code=end

