/*
 * @lc app=leetcode.cn id=374 lang=c
 *
 * [374] 猜数字大小
 *
 * https://leetcode-cn.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (43.37%)
 * Likes:    64
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 55.8K
 * Testcase Example:  '10\n6'
 *
 * 我们正在玩一个猜数字游戏。 游戏规则如下：
 * 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
 * 每次你猜错了，我会告诉你这个数字是大了还是小了。
 * 你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
 * 
 * -1 : 我的数字比较小
 * ⁠1 : 我的数字比较大
 * ⁠0 : 恭喜！你猜对了！
 * 
 * 
 * 
 * 
 * 示例 :
 * 
 * 输入: n = 10, pick = 6
 * 输出: 6
 * 
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
/**方法一：二分法
 * 100%
 * 100%
 *
int guess(int num);

int bin_search(int left, int right){
    int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(guess(mid) == 0){
            return mid;
        }
        else if(guess(mid) == 1){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return mid;
}

int guessNumber(int n){
    return bin_search(1, n);
}
*/
/**方法二：三分查找
 * 100%
 * 100%
 */
int guessNumber(int n){
	long int low, high, mid1, mid2;
    int flag1, flag2;

    low = 1;
    high = n;
    while(low <= high) {
        mid1 = low + (high - low) / 2;
        flag1 = guess(mid1);
        mid2 = high - (high - low) / 2;
        flag2 = guess(mid2);
        if(-1 == flag1) {
            high = mid1 - 1;
        } else if(1 == flag2) {
            low = mid2 + 1;
        } else if(0 == flag1) {
            return mid1;
        } else if(0 == flag2) {
            return mid2;
        }
    }
    return 0;
}
// @lc code=end

