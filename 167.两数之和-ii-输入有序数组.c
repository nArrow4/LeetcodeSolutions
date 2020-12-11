/*
 * @lc app=leetcode.cn id=167 lang=c
 *
 * [167] 两数之和 II - 输入有序数组
 *
 * https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/description/
 *
 * algorithms
 * Easy (53.12%)
 * Likes:    312
 * Dislikes: 0
 * Total Accepted:    101.5K
 * Total Submissions: 186.9K
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 * 
 * 说明:
 * 
 * 
 * 返回的下标值（index1 和 index2）不是从零开始的。
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 * 
 * 
 * 示例:
 * 
 * 输入: numbers = [2, 7, 11, 15], target = 9
 * 输出: [1,2]
 * 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 * 
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**解法一： 双指针法
 * 思路：左右两个指针向中间搜索
 * 优点：简单易懂
 * 缺点：复杂度高，耗时长
//左右指针同时向中间靠拢，步长为1
void bin_search(int* numbers, int numbersSize, int target, int* returnSize, int* res, int left, int right){
    int lnum, rnum;
    lnum = numbers[left];
    rnum = numbers[right];
    printf("%d %d", lnum, rnum);
    if(lnum + rnum == target){
        res[0] = left + 1;
        res[1] = right + 1;
        *returnSize = 2;
    }
    else{
        int mid = (left + right) / 2;
        if(lnum + rnum < target){
            bin_search(numbers, numbersSize, target, returnSize, res, left + 1, right);
        }
        else{
            bin_search(numbers, numbersSize, target, returnSize, res, left, right - 1);
        }
    }
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res;
    res = (int *)malloc(sizeof(int) * 2);
    bin_search(numbers, numbersSize, target, returnSize, res, 0, numbersSize - 1);
    return res;
}
*/
/**解法二：固定左指针
 * 思路：每次固定左指针，二分查找右指针
 * 速度比方法一快
 * 66.24%
 * 100%
 * 
void bin_search(int* numbers, int numbersSize, int target, int* returnSize, int* res, int index, int right){
    int left, lnum, mid, mnum, inum;
    inum = numbers[index];
    //开始查找右指针
    left = index + 1;
    while(left <= right){
        mid = (left + right) / 2;
        mnum = numbers[mid];
        if(mnum + inum == target){
            res[0] = index + 1;
            res[1] = mid + 1;
            *returnSize = 2;
            return;
        }
        else if(mnum + inum < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    bin_search(numbers, numbersSize, target, returnSize, res, index + 1, right);
    return;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res;
    res = (int *)malloc(sizeof(int) * 2);
    bin_search(numbers, numbersSize, target, returnSize, res, 0, numbersSize - 1);
    return res;
}
*/
/**方法三：固定右指针
 * 思路：先固定右指针，再查找左指针
 * trick：这样会比，方法二更快，因为可以先根据target的大小筛选。（本题有负数）
 * 66.24%
 * 100%
 * 好吧实际上并没有变快，应该是数据集设置问题，numbers中较大的数没有设置很多。
 *
void bin_search(int* numbers, int numbersSize, int target, int* returnSize, int* res, int index, int right){
    int left, lnum, mid, mnum, inum;
    inum = numbers[index];
    //开始查找右指针
    left = index + 1;
    while(left <= right){
        mid = (left + right) / 2;
        mnum = numbers[mid];
        if(mnum + inum == target){
            res[0] = index + 1;
            res[1] = mid + 1;
            *returnSize = 2;
            return;
        }
        else if(mnum + inum < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    bin_search(numbers, numbersSize, target, returnSize, res, index + 1, right);
    return;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res, right;
    res = (int *)malloc(sizeof(int) * 2);
    right = numbersSize - 1;
    while(target < numbers[right] + numbers[0])
        right--;
    bin_search(numbers, numbersSize, target, returnSize, res, 0, right);
    return res;
}
*/
/**方法四：左右同时二分查找
 * 思路：这是方法二、方法三的融合。如果left、right对应值的和比target大，说明right需要左移。
 *      于是固定left，对right二分。当然二分可能找不到合适的值，结束时二分查找函数中的两个值
 *      相等，返回给right。此时right对应的数一定是比需要查找的数小的，而且是“擦边”小的。所
 *      以返回后左右两个数的和必定是大于target的，这时候就再去类似地找left。
 *      注意left需要搜索到更大的那个，right需要搜索到更小的那个。
 * 66.24%->99.36%（在left-1，right+1那里修改边界条件后）
 * 100%
 * 貌似这也不是最优的解法。
 */
int bin_search(int* numbers, int numbersSize, int target, int* returnSize, int left, int right, int isleft){
    int mid;
    while(left <= right){
        mid = (left + right) / 2;
        if(numbers[mid] == target){
            return mid;
        }
        else if(numbers[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    if(isleft == 1)
        return left;
    else
        return left - 1;
}

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *res, right, left;
    res = (int *)malloc(sizeof(int) * 2);
    left = 0;
    right = numbersSize - 1;
    while(target < numbers[right] + numbers[0])
        right--;
    while(left < right){
        if(numbers[right]+numbers[left]==target){
            res[0] = left+1;
            res[1] = right+1;
            *returnSize = 2;
            return res;
        }
        else if(numbers[right]+numbers[left] < target){
            left = bin_search(numbers, numbersSize, target-numbers[right], returnSize, left, right-1, 1);
        }
        else{
            right = bin_search(numbers, numbersSize, target-numbers[left], returnSize, left+1, right, 0);
        }
    }
    return res;
}
// @lc code=end

