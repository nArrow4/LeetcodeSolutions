/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (47.08%)
 * Likes:    458
 * Dislikes: 0
 * Total Accepted:    128.5K
 * Total Submissions: 272.8K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int index = m + n - 1, i = m - 1, j = n - 1;
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[index--] = nums1[i--];
        }
        else{
            nums1[index--] = nums2[j--];
        }
    }
    while(j >= 0){
        nums1[index--] = nums2[j--];
    }
    return;
}
/*归并排序
从后往前遍历，取大的数存到1中
然后处理2中多出来的数（如果有的话）
*/
/*解法二.插入排序
每次从小往大扫描nums2，同时对于
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i=0;i<n;i++){
        int j=m-1;
        for(;j>=0;j--){
            if(nums2[i]>nums1[j]){
                nums1[j+1] = nums1[j];
            }
            else break;
        }
        nums1[j+1] = nums2[i];
        m++;
    }    
}
*/
/*解法三
把nums2储存到nums1后面
然后排序
*/
// @lc code=end
