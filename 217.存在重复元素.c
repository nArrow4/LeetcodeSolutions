/*
 * @lc app=leetcode.cn id=217 lang=c
 *
 * [217] 存在重复元素
 */

// @lc code=start

/**方法一：排序
 * 思路：
 * T:O(nlogn)
 * S:O(1)
 */
// int cmp(const void* a, const void *b){
//     return *(int *)a - *(int *)b;
// }

// bool containsDuplicate(int* nums, int numsSize){
//     qsort(nums, numsSize, sizeof(int), cmp);
//     for (int i = 0; i < numsSize - 1; i++){
//         if(nums[i] == nums[i+1])
//             return true;
//     }
//     return false;
// }

/**方法二：哈希表
 * 
 * 
 * 
 */
// #include <uthash.h>
// #include <stdlib.h>
typedef struct hashTable{
    int key;
    UT_hash_handle hh;
} HT;

bool containsDuplicate(int* nums, int numsSize){
    HT *set = NULL;
    for (int i = 0; i < numsSize; i++) {
        HT* tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}

// @lc code=end

