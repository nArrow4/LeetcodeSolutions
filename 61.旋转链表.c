/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
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
找到分割点，打断链表，再拼接
注意点：
1.
有几个卡点：
链表为空
k=0或为len的倍数
*/

struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head)
        return NULL;
    if(k == 0)
        return head;
    int len = 0, num;
    struct ListNode *ret, *p, *tail;
    p = head;
    while(p){
        len++;
        p = p->next;
    }
    if(len){
        k = k % len;
        num = len - k;
    }
    if(num == 0)
        return head;
    p = head;
    for (int i = 0; i < num - 1; i++){
        p = p->next;
    }
    if(p->next == NULL)
        return head;
    ret = p->next;
    tail = ret;
    p->next = NULL;
    for (int i = 0; i < k - 1; i++){
        tail = tail->next;
    }
    tail->next = head;
    return ret;
}


// @lc code=end

