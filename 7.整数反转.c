/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start

int reverse(int x){
    long long res = 0;
    while (x != 0){
        res = res * 10 + x % 10;
        x /= 10;
    }
    if((int)res!=res)
        return 0;
    return res;
}
/*
wtnl，时间卡的这么紧
思路比较简单吧
就是要判断越界的情况
 取原数的int
*/
// @lc code=end

