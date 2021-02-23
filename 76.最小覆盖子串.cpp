/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    bool check(std::unordered_map<char, int>umap_t, std::unordered_map<char, int>umap_s){
        for(auto &p : umap_t){
            if(umap_s[p.first] < p.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        std::unordered_map<char, int> umap_t, umap_s;
        std::string res;
        int left = 0;
        int right = 0;
        int m = t.length();
        for (int i = 0; i < m; i++){
            if(!umap_t.count(t[i])){
                umap_t[t[i]] = 1;
            }
            else {
                umap_t[t[i]]++;
            }
        }
        int n = s.length();
        while(right < n){
            if(!umap_s.count(t[i])){
                umap_s[t[i]] = 1;
            }
            else {
                umap_s[t[i]]++;
            }
            while(left <= right && !umap_t.count(s[left])){
                left++;
            }
            if(check(umap_t, umap_s)){
                res = &s[left];
                
            }
            right++;
        }
    }
};
// @lc code=end

