/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
思路：
先保留m前一个节点和n后一个节点，把m到n中间的节点都储存到数组里，反向遍历改变方向。
*/

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode *pHead, *pre, *cur, *pm, *pn, *p[n - m + 1];
    if(!head)
        return NULL;
    pHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre = pHead;
    cur = pHead;
    pHead->next = head;
    //pre->m->...->n->cur
    for (int i = 0; i < m - 1; i++)
        pre = pre->next;
    pm = pre->next;
    for (int i = 0; i < n; i++)
        cur = cur->next;
    pn = cur;
    cur = cur->next;
    for (int i = 0; i < n - m + 1; i++){
        p[i] = pm;
        pm = pm->next;
    }
    pm = pre->next;
    for (int i = n - m - 1; i >= 0; i--){
        p[i + 1]->next = p[i];
    }
    pm->next = cur;
    pre->next = pn;
    return pHead->next;
}


// @lc code=end

