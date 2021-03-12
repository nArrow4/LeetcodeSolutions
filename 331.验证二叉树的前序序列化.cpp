/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> num;
        num.push(1);            // 根节点特殊处理，只能插一个数
        int len = preorder.length();
        int i = 0;
        for (; i < len; i++)
        {
            while(!num.empty() && num.top() == 0){
                num.pop();
            }
            if(num.empty())
                break;
            if(preorder[i] == '#'){     // 空节点
                num.top()--;
            }
            else if(preorder[i] == ','){
                continue;
            }
            else{                       // 非空节点
                while(i<len && preorder[i] >='0' && preorder[i] <= '9'){
                    i++;
                }
                i--;            //这句也可以不加，反正下一个肯定是逗号
                num.top()--;
                num.push(2);
            }
        }
        if(i != len || !num.empty())
            return false;
        return true;
    }
};
// @lc code=end

