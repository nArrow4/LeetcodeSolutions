/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */
#include<bits/stdc++.h>
// @lc code=start
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = 0;
        int ret = 1;
        while(right < n){
            if(left == right){
                if(right+1<n && arr[left] == arr[right+1]){
                    left = right + 1;
                    right = left;
                }
                else{
                    right++;
                }
            }
            else{
                if(right+1<n && right>0 && 
                    (arr[right]>arr[right-1] && arr[right]>arr[right+1] ||
                    arr[right]<arr[right-1] && arr[right]<arr[right+1]))
                {
                    right++;
                }
                else{
                    ret = fmax(ret, right - left + 1);
                    left = right;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

