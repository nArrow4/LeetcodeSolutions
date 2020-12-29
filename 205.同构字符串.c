/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start

/**方法一：hash
 * 
 * 
 * 
 * 
 */
bool isIsomorphic(char * s, char * t){
    int hash[128];
    int len = strlen(s);
    memset(hash, 0, sizeof(hash));
    for(int i=0;i<len;i++){
        if(!hash[s[i]]){
            //缺少重复检测
            for(int j=0;j<128;j++){
                if(hash[j] != 0 && hash[j] == t[i]) return false;
            }
            hash[s[i]] = t[i];
        }
        else if(hash[s[i]] != t[i]) return false;
    }
    return true;
}

// @lc code=end

