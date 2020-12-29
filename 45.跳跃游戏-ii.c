/*
 * @lc app=leetcode.cn id=45 lang=c
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

/**方法一：贪心
 * 思路：每次找到在当前能走到的范围内找能使下一步移动最远的位置
 * T:O(n)
 * S:O(1)
 */
int jump(int* nums, int numsSize){
    if(numsSize == 1)
        return 0;
    int cnt = 0, cur_max, cur_j;
    for (int i = 0; i < numsSize; i++){
        cur_max = 0;
        if(i + nums[i] >= numsSize - 1)
            return cnt + 1;
        for (int j = i + 1; j < numsSize && j <= i + nums[i]; j++){
            if(cur_max < j + nums[j]){
                cur_max = j + nums[j];
                cur_j = j;
            }
        }
        if(cur_j > i){
            i = cur_j - 1;
        }
        cnt++;
    }
    return cnt;
}
// @lc code=end

