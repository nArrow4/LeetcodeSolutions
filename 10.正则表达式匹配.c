/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
/**方法一：直接解析正则表达式
 * 思路：还有点问题
 * 
 * 
 */
// #include<string.h>
// bool isMatch(char * s, char * p){
//     int sLen = strlen(s);
//     int pLen = strlen(p);
//     int pos = 0;
//     for (int i = 0; i < pLen; i++){
//         if(p[i] == '*')
//             continue;
//         if(i+1 < pLen && p[i+1] == '*'){
            
//             while(s[pos] == p[i])
//                 pos++;
//         }
//         else{
//             if(p[i] == '.'){
//                 pos++;
//             }
//             else{
//                 if(p[i] == s[pos])
//                     pos++;
//                 else
//                     return false;
//             }
//         }
//     }
//     if(pos == sLen)
//         return true;
//     else
//         return false;
// }
// @lc code=end

