/*
 * @lc app=leetcode.cn id=153 lang=c
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (50.23%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    55.1K
 * Total Submissions: 108.1K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 * 
 */

// @lc code=start

/**方法一：二分法
 *  
 * 64.07% 
 * 100%
 */
int findMin(int* nums, int numsSize){
    if(numsSize == 1)
        return nums[0];
    int left, right, mid;
    left = 0;
    right = numsSize - 1;
    if(nums[left] < nums[right]){
        return nums[left];
    }
    while(left <= right){
        mid = left + (right - left) / 2;
        if(mid != 0 && nums[mid] < nums[mid-1]){
            return nums[mid];
        }
        else if(nums[mid] <= nums[right]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return nums[left];
}


// @lc code=end

