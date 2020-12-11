/*
 * @lc app=leetcode.cn id=445 lang=c
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(L1->val == 0 && !L1->next)
        return L2;
    if(L2->val == 0 && !L2->next)
        return L1;
}


// @lc code=end

