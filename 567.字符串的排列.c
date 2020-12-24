/*
 * @lc app=leetcode.cn id=567 lang=c
 *
 * [567] 字符串的排列
 */

// @lc code=start

/**方法一：滑窗
 * 思路：也就是说s1的所有字母都在s2的连续子序列中
 * 
 * 
 */
#include<string.h>
bool checkInclusion(char * s1, char * s2){
    int left = 0, right = 0;
    int hash[26]={0};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len2 < len1)
        return false;
    for (int i = 0; i < len1; i++){
        hash[s1[i] - 'a']++;
        hash[s2[i] - 'a']--;
    }
    right = left + len1;
    while(right < len2){
        printf("%d %d\n", left, right);
        int flag = 1;
        for (int i = 0; i < 26; i++){
            if(!hash[s1[i]-'a']){
                flag = 0;
                hash[s2[left] - 'a']++;
                hash[s2[right] - 'a']--;
                left++, right++;
            }
        }
        if(flag == 1)
            return true;
    }
    return true;
}
// @lc code=end

