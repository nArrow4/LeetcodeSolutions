/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.00%)
 * Likes:    641
 * Dislikes: 0
 * Total Accepted:    95.9K
 * Total Submissions: 180.9K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define maxn 1000
void backTracking(char* digits, int* returnSize, char** alpha, char** res, int pos){
    int len = strlen(digits);
    if(pos == len){
        res[*returnSize][pos] = '\0';
        (*returnSize)++;
        res[*returnSize] = (char *)malloc(sizeof(char) * (len+1));
        memcpy(res[*returnSize], res[*returnSize - 1], sizeof(char)*pos);
        return;
    }
    else{
        int index, num = digits[pos] - '0';
        //遍历digit，取出对应的字母，递归
        int num_len = strlen(alpha[num]);
        for (int index = 0; index < num_len; index++){
            res[*returnSize][pos] = alpha[num][index];
            backTracking(digits, returnSize, alpha, res, pos + 1);
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    char *alpha[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char **res;
    res = (char **)malloc(sizeof(char *) * maxn);
    *returnSize = 0;
    res[*returnSize] = (char *)malloc(sizeof(char) * (strlen(digits)+1));
    if(strlen(digits) == 0)
        return res;
    backTracking(digits, returnSize, alpha, res, 0);
    return res;
}

/*
void dfs(int d){
	if(d==n)
		return(void)printf("\"%s\", ",t+1);
	for(int i=0;i<Len[s[d]-'0'];++i)
		t[d]=Alpha[s[d]-'0'][i],
		dfs(d+1);
}
*/
// @lc code=end

