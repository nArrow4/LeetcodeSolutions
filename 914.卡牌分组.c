/*
 * @lc app=leetcode.cn id=914 lang=c
 *
 * [914] 卡牌分组
 */

// @lc code=start

/**方法一：BF
 * 思路：直接记录deck中各元素的个数，然后用N去尝试整除。
 * T:O(n^2)
 * S:O(n)
 */
#include <string.h>
bool hasGroupsSizeX(int* deck, int deckSize){
    int count[10000], flag = 1;
    memset(count, 0, sizeof(int) * 10000);
    for(int i=0; i<deckSize; i++){
        count[deck[i]]++;
    }
    for (int N = 2; N <= deckSize; N++){
        flag = 1;
        for (int i = 0; i < deckSize && flag; i++){
            if(count[i] % N != 0){
                flag = 0;
            }
        }
        if(flag)
            return true;
    }
    return false;
}

/**方法二：gcd
 * 思路：用gcd求每个数出现次数的最小公因数
 * T:O(NlogC)
 * S:O(N+C)
 *
int gcd(int n1, int n2){
    return n1 == 0 ? n2 : gcd(n2 % n1, n1);
}

bool hasGroupsSizeX(int* deck, int deckSize){
    int count[10000], max = 0;
    for (int i = 0; i < deckSize; i++){
        count[deck[i]]++;
        max = max > deck[i] ? max : deck[i];
    }
    int n1 = count[max], n2;
    if(n1 < 2)
        return false;
    for (int i = 0; i < max; i++){
        if(count[i]){
            n2 = count[i];
            n1 = gcd(n1, n2);
            if(n1 == 1)
                return false;
        }
    }
    if(n1 >= 2)
        return true;
    return false;
}
*/
// @lc code=end

