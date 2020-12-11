/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.29%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    72.3K
 * Total Submissions: 138.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start


char * addBinary(char * a, char * b){
    int len_a, len_b, carry = 0, num_a, num_b, index, sum;
    char *res;
    len_a = strlen(a);
    len_b = strlen(b);
    res = (char *)malloc(sizeof(char) * (len_a + len_b + 10));
    index = len_a + len_b + 9;
    res[index--] = '\0';
    for (int i = len_a - 1, j = len_b - 1; i >= 0 || j >= 0 || carry; i--, j--){
        num_a = i >= 0 ? a[i] - '0' : 0;
        num_b = j >= 0 ? b[j] - '0' : 0;
        sum = (num_a + num_b + carry) % 2;
        carry = (num_a + num_b + carry) / 2;
        res[index--] = sum + '0';
    }
    return res+index+1;
}
/*
由于两个字符串的长度不一定一样
所以在短的字符串前面补0
当然，如果长度相等（首位必为1），就需要增长
*/

// @lc code=end

