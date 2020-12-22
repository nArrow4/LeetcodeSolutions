/*
 * @lc app=leetcode.cn id=424 lang=c
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start

/**方法一：滑动窗口 & Hash
 * 思路：滑窗的题由三部分组成：
 *          1.扩张：right右移
 *          2.收缩：left右移
 * T:O(n)
 * S:O(1)
 */
int characterReplacement(char * s, int k){
    int left = 0, right = 0, max = 0, ans = 0;
    int len = strlen(s);
    int hash[26] = {0};
    while(right < len){
        int index = s[right] - 'A';
        hash[index]++;
        max = fmax(max, hash[index]);
        if(right - left + 1 > max + k){     //收缩
            hash[s[left] - 'A']--;
            left++;
        }
        ans = fmax(ans, right - left + 1);
        right++;                            //滑动
    }
    return ans;
}


// @lc code=end

