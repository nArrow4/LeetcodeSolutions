/*
 * @lc app=leetcode.cn id=367 lang=c
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.27%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    35.2K
 * Total Submissions: 81.1K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
/**方法一：二分查找
 * 思路：先将范围约束在【0，n/2】，然后特判1、0。
 * 100%
 * 100%
 *
int bin_search(long int left,long int right, int n){
    long int mid;
    while(left <= right){
        mid = left + (right - left) / 2;
        //printf("%d %d %d\n", left, right, mid);
        if(mid*mid == n){
            return 1;
        }
        else if(mid*mid > n){
            if((mid-1)*(mid-1)<n){
                return 0;
            }
            else
                right = mid - 1;
        }
        else{
            if((mid+1)*(mid+1)>n){
                return 0;
            }
            else
                left = mid + 1;
        }
    }
    return 0;
}

bool isPerfectSquare(int num){
    if(num == 0)
        return false;
    if(num == 1)
        return true;
    return bin_search(1, num / 2, num);
}*/
/**方法二：数学法
 * 思路：完全平方数可以写成多个奇数正整数的和。
 *      如4=1+3
 *        9=1+3+5
 *        16=1+3+5+7
 * 100%
 * 100%
bool isPerfectSquare(int num){
    if (num == 0 ) return false;
    int i = 1;
    while ( num > 0){
        num -= i;
        i += 2;
    }
    return num == 0 ? true : false;
    //return num == 0;
}
*/
/**方法三：更简洁的二分版本
 * 100%
 * 100%
 *
bool isPerfectSquare(int num){
    long long int low=0,high=num/2+1,mid=0;

    while(low<=high){
        mid=(low+high)/2;

        if(mid*mid<num) low=mid+1;
        else if(mid*mid>num) high=mid-1;
        else break; 
    }
    if(low>high) return false;
    else return true;
}
*/
// @lc code=end

