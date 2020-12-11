/*
 * @lc app=leetcode.cn id=151 lang=c
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (36.95%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 137.1K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 * 
 * 
 * 示例 2：
 * 
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 
 * 
 * 示例 3：
 * 
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 * 
 */

// @lc code=start

//用栈实现
char * reverseWords(char * s){
    int len = strlen(s);
    if(len == 0)
        return s;
    char *res = (char *)malloc(sizeof(char) * (strlen(s) + 2));
    char *stack = (char *)malloc(sizeof(char) * (strlen(s) + 2));
    int i, t = 0, count = 0, flag = 0;
    for(i = len - 1;i >= 0;i--)
    {
        if(s[i] != ' ')
        {
            stack[t++] = s[i];
            flag = 1;
        }
        if(s[i] == ' ')
        {
            while(t > 0)
                res[count++] = stack[--t];
            if(flag == 1)
                res[count++] = ' ';
            flag = 0;
        }
    }
    if(t == 0)
    {
        if(count > 0)
            count--;
    }
    while(t > 0)
        res[count++] = stack[--t];
    res[count] = '\0';
    return res;
}

/*暴力法，甚至开到10000也会炸，不可取
#define maxn 100000

void removeMultipleSpace(char* s, int len){
    int flag=1, index;
    for(int i=0;i<len;i++){
        if(s[i] == ' ' && s[i+1] == ' '){
            index=i;
            while(s[index]){
                s[index]=s[index+1];
                index++;
            }
            i--;
        }
    }
}

void reverse(char* s, int start, int len){
    char tmp;
    for(int i=0;i<len/2;i++){
        tmp = *(s+start+i);
        *(s+start+i) = *(s+start+len-1-i);
        *(s+start+len-i-1) = tmp;
    }
}

char * reverseWords(char * s){
    char *res;
    int len = strlen(s), front, rear;
    res = (char*)malloc(sizeof(char)*maxn);
    memset(res, 0, sizeof(char)*maxn);
    while(isspace(*s)) s++, len--;
    reverse(s, 0, len);
    while(isspace(*s)) s++, len--;
    front = 0;
    rear = 0;
    removeMultipleSpace(s, len);
    while(s[rear] != '\0'){
        while(s[rear] && s[rear] == ' ') rear++;
        front = rear;
        if(s[front] == '\0') break;
        while(s[rear] && s[rear] != ' ') rear++;
        reverse(s, front, rear-front);
    }
    strcpy(res, s);
    return res;
}
*/

// @lc code=end

