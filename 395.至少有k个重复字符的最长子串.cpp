/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int res = 0;
        for (int i = 0; i <= n/k; i++){
            // std::cout << i << std::endl;
            int left = 0;
            int right = 0;
            std::unordered_map<char, int> umap;
            while(right < n){
                if(!umap.count(s[right])){
                    umap[s[right]] = 1;
                }
                else{
                    umap[s[right]]++;
                }
                // 区间内缩
                while(umap.size() > i){
                    umap[s[left]]--;
                    if(umap[s[left]] == 0)
                        umap.erase(s[left]);
                    left++;
                }
                if(check(umap, k)){
                    // std::cout << right << " " << left << std::endl;
                    res = fmax(res, right - left + 1);
                }
                // 区间外扩
                right++;
            }
        }
        return res;
    }
    bool check(std::unordered_map<char, int> umap, int k){
        for(auto& c : umap){
            // std::cout << c.first << " " << c.second << std::endl;
            if(c.second < k){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

