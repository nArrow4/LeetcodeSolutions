/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int time = customers.size();
        int ret = 0;
        int left = -X+1;
        int right = 0;
        int max = 0;
        int total = 0;
        while(right < time){
            ret += grumpy[right] == 0 ? customers[right] : 0;
            if(grumpy[right] == 1){
                total += customers[right];
            }
            if(left > 0 && grumpy[left - 1] == 1){
                total -= customers[left - 1];
            }
            max = fmax(max, total);
            left++, right++;
        }
        return ret + max;
    }
};
// @lc code=end

