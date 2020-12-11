/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <limits.h>

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int index, min=INT_MAX;
    for (int i = 0; i < listsSize; i++){
        if(listsNode[i]->val > min){
            min = listsNode[i]->val;
            index = i;
        }
    }
}
// @lc code=end

