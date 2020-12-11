/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (45.34%)
 * Likes:    468
 * Dislikes: 0
 * Total Accepted:    136.1K
 * Total Submissions: 299.9K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize-1, mid;
    if(numsSize == 0)
        return 0;
    if(nums[right] < target)
        return numsSize;
    while(left < right){
        mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
/*二分法

*/
/*暴力搜索
一开始没写第一个if，只想着多个数的时候不能越界
结果WA了
还是功力不到位
int searchInsert(int* nums, int numsSize, int target){
    if(numsSize == 1){
        if(target<=*nums)
            return 0;
        else if(target>*nums)
            return 1;
    }
    for (int i = 0; i < numsSize-1; i++){
        if(target<*nums)
            return 0;
        else if(target>*(nums+numsSize-1))
            return numsSize;
        else if(target>*(nums+i) && target<=*(nums+i+1))
            return i + 1;
        if(*(nums+i)==target)
            return i;
    }
    return 0;
}
*/

// @lc code=end

