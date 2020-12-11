/*
 * @lc app=leetcode.cn id=60 lang=c
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.56%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    28.3K
 * Total Submissions: 58.4K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start
int factorial(int n)
{
    int num = 1;
    while (n > 0)
    {
        num *= n;
        n--;
    }
    return num;
}
void deleteItem(int *nums, int numsSize, int in)
{
    for (; in < numsSize - 1; in++)
        nums[in] = nums[in + 1];
}
char *getPermutation(int n, int k)
{
    int i, j = 0, nums[n], factor;
    char *res = (char *)malloc(sizeof(char) * 10);
    for (i = 1; i <= n; i++)
        nums[i - 1] = i;
    //k要先减一（考虑刚好等于边界的情况）
    for (i = 0,k--; i < n; i++) 
    {
        factor = factorial(n - i - 1);
        res[j++] = nums[k / factor] + '0';
        deleteItem(nums, n - i, k / factor);
        k %= factor;
    }
    res[j] = '\0';
    return res;
}


/*堆内存溢出？？有地方数组越界了
void permutation(int n, int k, int pos, char* res, char* tmp, int* cnt){
    if(pos == n){
        //判断是不是第k种
        (*cnt)++;
        if(*cnt == k)
            memcpy(res, tmp, sizeof(char) * n);
    }
    else{
        int flag;
        //1-n的全排序
        for (char i = '1'; i <= n+'0'; i++){
            flag = 1;
            //前面的位置没用过
            for (int j = 0; j < pos; j++){
                if(tmp[j] == i){
                    flag = 0; 
                    break;
                }
            }
            if(flag){
                tmp[pos] = i;
                permutation(n, k, pos + 1, res, tmp, cnt);
            }
        }
    }
}

char * getPermutation(int n, int k){
    int *cnt;
    char *res, *tmp;
    cnt = (int *)malloc(sizeof(int));
    res = (char *)malloc(sizeof(char) * 100);
    tmp = (char *)malloc(sizeof(char) * 100);
    *cnt = 0;
    permutation(n, k, 0, res, tmp, cnt);
    return res;
}
*/
// @lc code=end

