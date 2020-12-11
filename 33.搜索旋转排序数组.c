/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.51%)
 * Likes:    577
 * Dislikes: 0
 * Total Accepted:    89.7K
 * Total Submissions: 245.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
/**方法一：二分法
 * 思路：每次二分，找到有序区间
 * 71.39%
 * 100%
 */
int bin_search(int* nums, int numsSize, int target, int left, int right){
    int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target){
    if(numsSize == 0)
        return -1;
    if(numsSize == 1)
        return nums[0] == target ? 0 : -1;
    int left, right, mid;
    left = 0;
    right = numsSize - 1;
    while(left <= right){
        mid = left + (right - left) / 2;
        //末尾的数大的区间是有序的
        if(nums[mid] == target){
            return mid;
        }
        if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[numsSize - 1]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
    }
    return -1;
}


// @leftc code=end

