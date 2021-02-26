/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    bool check(std::unordered_map<char, int>umap_t){
        for(auto& elem : umap_t){
            // std::cout << elem.first << " " << elem.second << std::endl;
            // 这里一定要是大于0
            if(elem.second > 0){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        std::unordered_map<char, int> umap_t;
        std::string res;
        int left = 0;
        int right = 0;
        int minLen = INT_MAX;
        int m = t.length();
        // 记录t中所有字符出现次数
        for (int i = 0; i < m; i++){
            if(umap_t.find(t[i]) == umap_t.end()){
                umap_t[t[i]] = 1;
            }
            else {
                umap_t[t[i]]++;
            }
            // std::cout << t[i] << " " << umap_t[t[i]] << std::endl;
        }
        int n = s.length();
        while(right < n){
            if(umap_t.find(s[right]) != umap_t.end()){
                umap_t[s[right]]--;
            }
            // 区间内缩
            while(left <= right){
                if(umap_t.find(s[left]) == umap_t.end())
                    left++;
                else if(umap_t[s[left]] < 0){
                    umap_t[s[left]]++;
                    left++;
                }
                else
                    break;
            }
            // 检查是否覆盖
            if(check(umap_t) && minLen > right-left+1){
                minLen = right - left + 1;
                // std::cout << minLen << std::endl;
                res = s.substr(left, minLen);
                umap_t[s[left]]++;
                left++;
            }
            // 区间外扩
            right++;
        }
        return res;
    }
};
// @lc code=end

