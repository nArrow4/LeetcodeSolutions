/*
 * @lc app=leetcode.cn id=3 lang=c
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

/**方法一：滑动窗口 & Hash
 * 思路：当left递增时，right必然递增。
 * T:O(n)
 * S:O(1)
 */
#include<string.h>
int lengthOfLongestSubstring(char * s){
    int hash[256];
    memset(hash, 0, sizeof(int) * 256);
    int left = 0, right = 0, ans = 0;
    int len = strlen(s);
    while(left <= right && right < len){
        hash[s[left]] = 1;
        while(right + 1 < len && hash[s[right + 1]] == 0){
            hash[s[right + 1]] = 1;
            right++;
        }
        ans = fmax(ans, right - left + 1);
        printf("%d %d\n", left, right);
        hash[s[left]] = 0;
        left++;
        right = right > left ? right : left;
    }
    return ans;
}
// @lc code=end

