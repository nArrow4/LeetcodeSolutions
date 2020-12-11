/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int pre, index=0;
    for (int i = 0; i < numsSize; i++){
        if(nums[i]!=pre){
            pre = nums[i];
            nums[index++] = pre;
        }
    }
    return index;
}
/*
双指针法
一个遍历，遇到不重复的，就赋给另一指针
*/

// @lc code=end

