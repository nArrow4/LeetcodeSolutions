/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode *odd, *p = head, *even, *p1, *p2;
    if(!head || !head->next)
        return head;
    
    int flag = 0;
    odd = (struct ListNode *)malloc(sizeof(struct ListNode));
    even = (struct ListNode *)malloc(sizeof(struct ListNode));
    p1 = odd;
    p2 = even;
    while(p){
        if(flag%2 == 1){
            //even
            even->next = p;
            even = even->next;
        }
        else{
            //odd
            odd->next = p;
            odd = odd->next;
        }
        flag++;
        p = p->next;
    }
    odd->next = p2->next;
    even->next = NULL;
    return p1->next;
}
// @lc code=end

