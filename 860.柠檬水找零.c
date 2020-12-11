/*
 * @lc app=leetcode.cn id=860 lang=c
 *
 * [860] 柠檬水找零
 */

// @lc code=start

/**方法一：贪心
 * 思路：每次收钱的时候，对应的money数量增加。找钱时，
 *          1.如果收到10元，money[0]--
 *          2.如果收到20元，优先使用10元找零
 * T:O(n)
 * S:O(1)
 */
bool lemonadeChange(int* bills, int billsSize){
    if(bills[0] != 5)
        return false;
    int money[2] = {0, 0};
    for (int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            money[0]++;
        }
        else if(bills[i] == 10){
            money[1]++;
            money[0]--;
        }
        else{
            if(money[1]){
                money[1]--, money[0]--;
            }
            else{
                money[0] -= 3;
            }
        }
        if(money[0] < 0 || money[1] < 0)
            return false;
    }
    return true;
}


// @lc code=end

