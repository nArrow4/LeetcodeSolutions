/*
 * @lc app=leetcode.cn id=89 lang=c
 *
 * [89] 格雷编码
 *
 * https://leetcode-cn.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (67.87%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    21.9K
 * Total Submissions: 32.2K
 * Testcase Example:  '2'
 *
 * 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
 * 
 * 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: [0,1,3,2]
 * 解释:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * 对于给定的 n，其格雷编码序列并不唯一。
 * 例如，[0,2,3,1] 也是一个有效的格雷编码序列。
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 示例 2:
 * 
 * 输入: 0
 * 输出: [0]
 * 解释: 我们定义格雷编码序列必须以 0 开头。
 * 给定编码总位数为 n 的格雷编码序列，其长度为 2^n。当 n = 0 时，长度为 2^0 = 1。
 * 因此，当 n = 0 时，其格雷编码序列为 [0]。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //n的编码是n-1正序接上n-1倒序且每个加2^(n-1)
int* grayCode(int n, int* returnSize)
{
    int len=pow(2,n);
    int*gray=(int*)malloc(sizeof(long int)*(len));
    gray[0]=0;
    for(int i=1;i<=n;i++)
    {
        int pos=1;
        int pre_len=pow(2,(i-1));
        int cur_len=pow(2,(i));
        for(int i=pre_len;i<cur_len;i++)
        {
            if(pre_len-pos>=0)
            { 
                 gray[i]=gray[pre_len-pos]+pre_len;
                 pos++;
            }
          
        }
    }
    *returnSize=len;
    return gray;
}
/*
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
int* grayCode(int n, int* returnSize){
    int total=pow(2.0,n);
    int *res=malloc(sizeof(int)*total);
    *returnSize=total;
    for(int i=0;i<total;i++){
        res[i]=(i>>1)^i;
    }
    return res;
}
*/
// @lc code=end

