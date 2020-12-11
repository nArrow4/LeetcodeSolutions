/*
 * @lc app=leetcode.cn id=38 lang=c
 *
 * [38] 外观数列
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (54.67%)
 * Likes:    430
 * Dislikes: 0
 * Total Accepted:    84.3K
 * Total Submissions: 154.1K
 * Testcase Example:  '1'
 *
 * 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * 
 * 注意：整数序列中的每一项将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 解释：这是一个基本样例。
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 =
 * 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。
 * 
 */

// @lc code=start


char * countAndSay(int n){
    char *nums, rec, *res;
    int cnt = 0, len, index = -1;
    if(n == 1){
        return "1";
    }
    nums = (char *)malloc(sizeof(char) * 5000);
    nums = countAndSay(n - 1);
    len = strlen(nums);
    res = (char *)malloc(sizeof(char) * len * 2 + 1);
    rec = *nums;
    for (char *p = nums; *p; p++){
        if(rec != *p){
            res[++index] = cnt + '0';
            res[++index] = rec;
            rec = *p;
            cnt = 1;
        }
        else
            cnt++;
    }
    res[++index] = cnt + '0';
    res[++index] = rec;
    res[++index] = '\0';
    return res;
}
/*递归题
明确函数是干什么的
写结束条件，然后用n-1的结果计算n
这一题数组越界比较麻烦
nums就直接开的5000
*/
/*解法二.尾递归
其实跟上面的思路差不多，就是换了一种写法
char *countHelper(char *s, int n)
{
    if (n == 1)
        return s;
    else
    {
        //求下一个数
        int count;
        char ch[10000];
        char *p = ch;
        //一直读数
        while (*s!='\0')
        {
            count = 1;
            //如果一直是同一个数
            while (*s==*(s+1))
            {
                count++;
                s++;
            }
            //下一个数更新
            *p++ = (char)(count+'0');
            *p++ = *s++;
        }
        return countHelper(ch, n - 1);
    }
}

char *countAndSay(int n)
{
    return countHelper("1", n);
}
*/
// @lc code=end

