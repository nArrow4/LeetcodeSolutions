/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.25%)
 * Likes:    365
 * Dislikes: 0
 * Total Accepted:    76.4K
 * Total Submissions: 194.5K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**方法一：二分法
 * 思路：先二分找到一个mid，然后在两边搜索
 * 52.69%
 * 100%
 * 
int bin_search(int* nums, int numsSize, int target){
    int left, right, mid;
    left = 0;
    right = numsSize - 1;
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
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res, pos, left, right;
    res = (int *)malloc(sizeof(int) * 2);
    pos = bin_search(nums, numsSize, target);
    if(pos == -1){
        res[0] = -1;
        res[1] = -1;
    }
    else{
        left = pos;
        right = pos;
        while(nums[right] == nums[pos]){
            if(right == numsSize - 1){
                right++;
                break;
            }
            else
                right++;
        }
        while(nums[left] == nums[pos]){
            if(left == 0){
                left--;
                break;
            }
            else
                left--;
        }
        res[0] = left + 1;
        res[1] = right - 1;
    }
    *returnSize = 2;
    return res;
}
*/
/**方法二：三次二分
 * 二分找到一个target，再在左右区间分别二分找边界
 * 52.69%
 * 100%
 *
int bin_search(int* nums, int numsSize, int target){
    int left, right, mid;
    left = 0;
    right = numsSize - 1;
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
int dir_bin_search(int* nums, int numsSize, int target, int pos, bool dir){
    int left, right, mid;
    left = dir?0:pos;
    right = dir?pos:numsSize - 1;
    while(left <= right){
        mid = left + (right - left) / 2;
        if(dir?(nums[mid]==target):(nums[mid]>target)){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return dir?(left):(right);
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res, pos;
    res = (int *)malloc(sizeof(int) * 2);
    pos = bin_search(nums, numsSize, target);
    if(pos == -1){
        res[0] = -1;
        res[1] = -1;
    }
    else{
        res[0] = dir_bin_search(nums, numsSize, target, pos, true);
        res[1] = dir_bin_search(nums, numsSize, target, pos, false);
    }
    *returnSize = 2;
    return res;
}
*/
// @lc code=end

