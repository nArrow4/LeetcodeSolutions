/*
 * @lc app=leetcode.cn id=441 lang=c
 *
 * [441] 排列硬币
 *
 * https://leetcode-cn.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (40.35%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 54.9K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
 * 
 * 给定一个数字 n，找出可形成完整阶梯行的总行数。
 * 
 * n 是一个非负整数，并且在32位有符号整型的范围内。
 * 
 * 示例 1:
 * 
 * 
 * n = 5
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * 因为第三行不完整，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * n = 8
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * 因为第四行不完整，所以返回3.
 * 
 * 
 */

// @lc code=start

/**方法一：暴力减
 * 
 * 73.67%
 * 100%
int arrangeCoins(int n){
    int i = 1;
    while(n > 0){
        n -= i;
        i++;
    }
    if(n == 0)
        return i - 1;
    else
        return i-2;
}
*/
/**方法二：数学法
 * 借用求和公式
 * 100%
 * 100%
int arrangeCoins(int n){       
    double dn = n;    
    double t = sqrt((8*dn + 1)/4) - 0.5;    
    return (int) t;  
}
*/
/**方法三：二分查找
 * 思路：为了缩小范围（0~n/2），前六个数需要单独判断。
 * 100%
 * 100%
 */
int arrangeCoins(int n){
    int res[7] = {0, 1, 1, 2, 2, 2, 3};
    if(n >= 0 && n <= 6)
        return res[n];
    else
    {
        int low = 1;
        int high = n / 2;
        while(low <= high)
        {
            long mid = low + (high - low)/2;
            long a = mid * (mid + 1)/2;
            if(a == n)
                return mid;
            else if(a > n)
                high = mid -1;
            else
                low = mid +1;
        }
        return low-1;
    }
}

// @lc code=end

