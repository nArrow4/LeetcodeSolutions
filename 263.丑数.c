/*
 * @lc app=leetcode.cn id=263 lang=c
 *
 * [263] 丑数
 */

// @lc code=start

/**
 * 
 * 
 * 
 */
bool isUgly(int num){
    if(num == 0)
        return false;
    while(num != 1){
        if(num % 2 == 0)
            num /= 2;
        else if(num % 3 == 0)
            num /= 3;
        else if(num % 5 == 0)
            num /= 5;
        else
            break;
    }
    if(num == 1)
        return true;
    return false;
}


// @lc code=end

