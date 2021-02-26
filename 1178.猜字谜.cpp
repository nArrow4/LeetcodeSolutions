/*
 * @lc app=leetcode.cn id=1178 lang=cpp
 *
 * [1178] 猜字谜
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        std::vector<int> res;
        int n = puzzles.size();
        int m = words.size();
        std::vector<std::pair<std::unordered_map<char, int>, char>> puz;
        std::vector<std::unordered_map<char, int>> wrd;
        for (int j = 0; j < m; j++){            //遍历所有的word
            std::unordered_map<char, int> umap;
            for(char& c : words[j]){
                if(umap.find(c) == umap.end()){
                    umap[c] = 1;
                }
            }
            wrd.push_back(umap);
        }
        for (int i = 0; i < n; i++){
            std::unordered_map<char, int> umap;
            char firstChar = puzzles[i][0];
            for(char& c : puzzles[i]){              //先储存puzzles中的所有字符
                if(umap.find(c) == umap.end()){
                    umap[c] = 1;
                }
            }
            int cnt = 0;
            for (int j = 0; j < m; j++){
                // if(wrd[j].find(firstChar) == wrd[j].end()){
                //     break;
                // }
                // if()
            }
            puz.push_back(std::make_pair(umap, firstChar));
        }
        return res;
    }
};

/**方法二：模拟（TLE）
 * 
 * 
 * 
 */
// class Solution {
// public:
//     vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
//         std::vector<int> res;
//         int n = puzzles.size();
//         int m = words.size();
//         for (int i = 0; i < n; i++){
//             std::unordered_map<char, int> umap;
//             int cnt = 0;
//             char firstChar = puzzles[i][0];
//             for(char& c : puzzles[i]){              //先储存puzzles中的所有字符
//                 if(umap.find(c) == umap.end()){
//                     umap[c] = 1;
//                 }
//             }
//             for (int j = 0; j < m; j++){            //遍历所有的word
//                 std::string word = words[j];
//                 bool flag1 = false, flag2 = true;
//                 for(char& c : word){
//                     if(c == firstChar){
//                         flag1 = true;
//                     }
//                     if(umap.find(c) == umap.end()){
//                         flag2 = false;
//                     }
//                 }
//                 if(flag1 && flag2){
//                     cnt++;
//                 }
//             }
//             res.push_back(cnt);
//         }
//         return res;
//     }
// };
// @lc code=end

