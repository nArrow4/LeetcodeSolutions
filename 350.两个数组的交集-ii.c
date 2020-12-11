/*
 * @lc app=leetcode.cn id=350 lang=c
 *
 * [350] 两个数组的交集 II
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (47.37%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    92.2K
 * Total Submissions: 188.9K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [4,9]
 * 
 * 说明：
 * 
 * 
 * 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 * 进阶:
 * 
 * 
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 * 
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**方法一：排序后，顺序取出
 *
 * 整体思路：
 * 1.快速排序后，维护两个指针，指向nums1和nums2
 * 2.如果两者相等则存入缓冲区，如果某一个值比较小，则移动该指针
 * 67.39%
 * 100%
 *
//quick sort, avoiding overflow
int cmp( const void * a , const void * b ){
    //if the value of a is bigger than the value of b
    if( *( int * )a > *( int * )b ){
        return 1;
    //if the value of a equal to the value of b
    } else if( *( int * )a == *( int * )b ){
        return 0;
    }
    //if the value of b is bigger than the value of a
    return -1;
}

int * intersect(int * nums1 , int nums1Size , int * nums2 , int nums2Size , int * returnSize){
    //alloclating memory to save the elements which in nums1 and nums2 at the same time
    int * buffer = ( int * )malloc( sizeof( int ) * nums1Size );
    //the parameter of i is point to nums1
    //the parameter of j is point to nums2
    int i = 0 , j = 0;
    //intializing the length of buffer
    *returnSize = 0;
    qsort( nums1 , nums1Size , sizeof( int ) , cmp );
    qsort( nums2 , nums2Size , sizeof( int ) , cmp );
    //visiting nums1 and nums2
    while( i < nums1Size && j < nums2Size ){
        if( *( nums1 + i ) == *( nums2 + j ) ){
            *( buffer + *returnSize ) = *( nums1 + i );
            *returnSize += 1;
            i++;
            j++;
        } else if( *( nums1 + i ) < *( nums2 + j ) ){
            i++;
        } else {
            j++;
        }
    }
    return buffer;
}
*/
/**方法二：二分查找
 * 67.39%
 * 100%
 *
#include<string.h>
int find_num(int *nums, int numsSize, int target){
    int right, left, mid;
    left = 0;
    right = numsSize - 1;
    
    while(left <= right){
        mid = (left + right) / 2;
        //printf("%d", nums[mid]);
        
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

int cmp( const void * a , const void * b ){

    //if the value of a is bigger than the value of b
    if( *( int * )a > *( int * )b ){
        return 1;
    //if the value of a equal to the value of b
    } else if( *( int * )a == *( int * )b ){
        return 0;
    }
    //if the value of b is bigger than the value of a
    return -1;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *res, cnt=0;
    res = (int *)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size+1 : nums2Size+1));  
    if(nums1Size==0 || nums2Size==0){
        res = NULL;
        *returnSize = 0;
        return res;
    }
    int flag[nums2Size];
    memset(flag, 0, sizeof(int) * nums2Size);
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    //在nums2中找nums1中的元素
    int index;
    for (int i = 0; i < nums1Size; i++){
        
        if((index = find_num(nums2, nums2Size, nums1[i])) != -1 && flag[index] == 0){
            res[cnt] = nums1[i];
            cnt++;
            for (int j = index; j>0 ; j--){
                nums2[j] = nums2[j - 1];
            }
            if(nums2Size > 1) {
                nums2++;
                nums2Size--;
            }
            else
                break;
        }
    }
    *returnSize = cnt;
    return res;
}
*/

// @lc code=end
