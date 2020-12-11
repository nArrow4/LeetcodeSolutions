/*
 * @lc app=leetcode.cn id=278 lang=c
 *
 * [278] 第一个错误的版本
 *
 * https://leetcode-cn.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (37.63%)
 * Likes:    175
 * Dislikes: 0
 * Total Accepted:    51.8K
 * Total Submissions: 132.3K
 * Testcase Example:  '5\n4'
 *
 * 
 * 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
 * 
 * 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
 * 
 * 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version
 * 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
 * 
 * 示例:
 * 
 * 给定 n = 5，并且 version = 4 是第一个错误的版本。
 * 
 * 调用 isBadVersion(3) -> false
 * 调用 isBadVersion(5) -> true
 * 调用 isBadVersion(4) -> true
 * 
 * 所以，4 是第一个错误的版本。 
 * 
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
/**
 * 思路：第i个是true，第i+1个是false
 * 100%
 * 100%
 */
int firstBadVersion(int n) {
    long int left, right, mid;
    left = 1;
    right = n;
    while(left<=right){
        mid = (left + right) / 2;
        //是好版本
        if(!isBadVersion(mid)){
            left = mid + 1;
        }
        //是坏版本
        else{
            if(mid == 1)
                return 1;
            //前一个是好版本
            else if(!isBadVersion(mid-1)){
                return mid;
            }
            right = mid - 1;
        }
    }
    return mid;
}

// @lc code=end

