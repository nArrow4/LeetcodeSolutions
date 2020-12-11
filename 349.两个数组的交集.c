/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.50%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    74.2K
 * Total Submissions: 106.7K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**方法一：二分法
 * 思路：nums1去重，在nums2中二分查找nums1
 * 69.11%
 * 100%
int find_num(int *nums, int numsSize, int target){
    int right, left, mid;
    left = 0;
    right = numsSize - 1;
    while(left <= right){
        mid = (left + right) / 2;
        if(nums[mid] == target){
            return 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return 0;
}

void swap(int* nums, int a, int b){
    int tmp;
    tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
    return;
}

int cmp(const void *a, const void *b){
    return *(int*)a - *(int *)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res, cnt=0;
    res = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    //nums1去重
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    for (int i = nums1Size - 1; i > 0; i--){
        if(nums1[i] == nums1[i-1]){
            swap(nums1, i, nums1Size-- - 1);
        }
    }
    //在nums2中找nums1中的元素
    for (int i = 0; i < nums1Size; i++){
        printf("%d ", nums1[i]);
        if(find_num(nums2, nums2Size, nums1[i]))
            res[cnt++] = nums1[i];
    }
    *returnSize = cnt;
    return res;
}
*/

/**方法二：排序遍历
 * 思路：分别排序，遍历添加，有重复的去重
 * 97.63%
 * 100%
 * 
int cmp(const void *a, const void *b){
    return *(int*)a - *(int *)b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res, cnt=0;
    res = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size; ) {
        if (nums1[i] < nums2[j])
            ++i;
        else if (nums1[i] > nums2[j])
            ++j;
        else {
            res[cnt++] = nums1[i];
            ++i;
            ++j;
            if (cnt > 1 && res[cnt-1] == res[cnt-2])
                --cnt;
        }
    }
    *returnSize = cnt;
    return res;
}
*/
// @lc code=end

