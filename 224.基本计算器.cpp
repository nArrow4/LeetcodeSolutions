/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution{
public:
    int calculate(string s){
        stack<int> ops;
        ops.push(1);
        int i = 0;
        int res = 0;
        int len = s.length();
        int isPositive = 1;
        for (int i = 0; i < len; i++){
            if(s[i] == ' '){
                continue;
            }
            else if(s[i] == '+'){
                isPositive = ops.top();
            }
            else if(s[i] == '-'){
                isPositive = -ops.top();
            }
            else if(s[i] == '('){       // 左括号中的数留着等括号中的数算完了再用
                ops.push(isPositive);
                // isPositive = 1;
            }
            else if(s[i] == ')'){
                ops.pop();
            }
            else{
                long num = 0;
                while(i < len && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                res += isPositive * num;
                i--;
            }
        }
        return res;
    }
};
// @lc code=end

