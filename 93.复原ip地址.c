/*
 * @lc app=leetcode.cn id=93 lang=c
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.21%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 74.7K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**方法一：递归
 * 思路：递归的模板需要注意两点：
 *          1. 递归的出口（一定要考虑详尽）
 *          2. 向下一层递归的状态转移
 * 
 * 注意：   1.72行realloc那里有点问题
 *          2."010010"。需要增加一个level=4但是start<len的出口
 * T:O()
 * S:O()    递归的复杂度不太会算，反正效率很低就是了
 */
#include<stdlib.h>
#include<string.h>
#include<math.h>
int str2int(char *s, int len){
    int ans = 0;
    for (int i = 0; i < len; i++){
        ans *= 10;
        ans += *(s + i) - '0';
    }
    return ans;
}
char * int2str(int num, int len){
    char *ans = (char *)malloc(sizeof(char) * 4);
    for (int i = len - 1; i >= 0; i--){
        ans[i] = num - num / 10 * 10 + '0';
        num /= 10;
    }
    ans[len] = '\0';
    return ans;
}

void dfs(char * s, char ** res, int* returnSize, int* segment, int level, int start){
    int len = strlen(s);
    if(level == 4 && start == len){ //退出条件
        char *ip;
        ip = (char *)malloc(sizeof(char) * (len + 4));
        int pos = -1;
        for (int i = 0; i < 4; i++){
            int tmp = segment[i];
            printf("%d\n", tmp);
            if(tmp / 100)   strcpy(ip + pos + 1, int2str(tmp, 3)), pos += 3, ip[++pos] = '.';
            else if(tmp / 10)   strcpy(ip + pos + 1, int2str(tmp, 2)), pos += 2, ip[++pos] = '.';
            else strcpy(ip + pos + 1, int2str(tmp, 1)), pos += 1, ip[++pos] = '.';
        }
        ip[pos] = '\0';
        // puts(ip);
        // res = (char **)realloc(res, sizeof(char *) * (*returnSize + 1));
        res[(*returnSize)] = (char *)malloc(sizeof(char) * (len + 10));
        strcpy(res[(*returnSize)],ip);
        (*returnSize)++;
        // free(ip), ip = NULL;
        return;
    }
    else if(start >= len)
        return;
    else if(level == 4)
        return;
    if(s[start] == '0'){                      //有前导0的情况
        segment[level] = 0;
        dfs(s, res, returnSize, segment, level + 1, start + 1);
    }
    else{
        if((4-level)*3 < len - start)           //后面的取满也不行，剪枝
                return;
        if(len - start > 0){                    //添加一个数字
            segment[level] = str2int(s + start, 1);
            // printf("%d %d 1\n", segment[level], level);
            dfs(s, res, returnSize, segment, level + 1, start + 1);
        }
        if(len - start > 1){                    //添加两个数字
            segment[level] = str2int(s + start, 2);
            // printf("%d %d 2\n", segment[level], level);
            dfs(s, res, returnSize, segment, level + 1, start + 2);
        }
        if(len - start > 2 && str2int(s + start ,3) <= 255){//添加三个数字
            segment[level] = str2int(s + start, 3);
            // printf("%d %d 3\n", segment[level], level);
            dfs(s, res, returnSize, segment, level + 1, start + 3);
        }
    }
    return;
}

char ** restoreIpAddresses(char * s, int* returnSize){
    char **res = (char **)malloc(sizeof(char*)*1000);
    int segment[4];
    int len = strlen(s);
    if(len < 4 || len > 12){
        (*returnSize) = 0;
        return res;
    }
    (*returnSize) = 0;
    dfs(s, res, returnSize, segment, 0, 0);
    // for (int i = 0; i < *returnSize; i++)
    //     puts(res[i]);
    return res;
}

// @lc code=end

