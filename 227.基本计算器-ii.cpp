/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    typedef enum
    {
        mul = 3,
        div = 2,
        add = 1,
        sub = -1,
    } OP;

    int calculate(string s) {
        stack<int> nums;
        OP flag = add;      // 记录当前数字的前一个算符 
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if(s[i] >= '0' && s[i] <= '9'){
                long num = 0;
                while(i < len && s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                i--;
                if(flag == add || flag == sub){
                    nums.push(num * flag);
                }
                else if(flag == mul){
                    long leftNum = nums.top();
                    nums.pop();
                    nums.push(leftNum * num);
                }
                else if(flag == div){
                    long leftNum = nums.top();
                    nums.pop();
                    nums.push(leftNum / num);
                }
            }
            else if(s[i] == ' '){
                continue;
            }
            else if(s[i] == '+'){
                flag = add;
            }
            else if(s[i] == '-'){
                flag = sub;
            }
            else if(s[i] == '*'){
                flag = mul;
            }
            else if(s[i] == '/'){
                flag = div;
            }
        }
        int res = 0;
        while(!nums.empty()){
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
// @lc code=end

