/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

    }
private:
    int Find(std::vector<int>& parent, int index){
        if(parent[index] != index){
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }
    void Union(std::vector<int>& parent, int index1, int index2){
        
    }
};
// @lc code=end

