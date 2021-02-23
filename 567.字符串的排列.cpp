/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> umap;
        int s1_size = s1.size();
        int s2_size = s2.size();
        int left = -s1_size+1;
        int right = 0;
        if(s1_size > s2_size)
            return false;
        for(char& c : s1){
            if(!umap.count(c)){
                umap[c] = 1;
            }
            else{
                umap[c]++;
            }
        }
        while(right < s2_size){
            // std::cout << umap.count(s2[right]) << std::endl;
            if(umap.find(s2[right]) != umap.end()){
                umap[s2[right]]--;
            }
            if(left>0 && umap.find(s2[left - 1]) != umap.end()){
                umap[s2[left - 1]]++;
            }
            // std::cout << umap[s2[right]] << std::endl;
            if(check(umap)){
                return true;
            }
            left++, right++;
        }
        return false;
    }
    bool check(std::unordered_map<char, int> umap){
        for(auto& elem : umap){
            // std::cout << elem.second << std::endl;
            if(elem.second != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

