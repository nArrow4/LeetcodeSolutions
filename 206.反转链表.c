/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
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
思路：将修改了指向的节点单独保存即可
*/
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p = head, *Head, *pre, *back;
    if(!head)
        return NULL;
    if(!head->next)
        return head;
    Head = (struct ListNode *)malloc(sizeof(struct ListNode));
    Head->next = head;
    pre = Head;
    //pre->p->back 2 pre<-p back 2 pre p->back
    while(p->next){
        back = p->next;
        p->next = pre;
        pre = p;
        p = back;
    }
    head->next = NULL;
    back->next = pre;
    return back;
}
/*
思路：递归
*/
// struct ListNode *reverseList(struct ListNode* head){
//     if(!head || !head->next)
//         return head;
//     struct ListNode *p = reverseList(head->next);
//     head->next->next = head;
//     head->next = NULL;
//     return p;
// }
// @lc code=end

