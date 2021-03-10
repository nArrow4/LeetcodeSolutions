/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string removeDuplicates(string S) {
        if(S.length() == 0 || S.length() == 1)
            return S;
        string res;
        for(char& c : S){
            if(res.empty()){
                res.push_back(c);
            }
            else if(res.back() == c){
                res.pop_back();
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }
};
// @lc code=end

