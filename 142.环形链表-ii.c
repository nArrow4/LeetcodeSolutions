/*
 * @lc app=leetcode.cn id=142 lang=c
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    if(head == NULL || head->next == NULL)
        return NULL;
    if(head->next == head)
        return head;
    fast = head->next;
    slow = head;
    int flag = fast - slow;
    //printf("%d ", flag);
    while(fast->next && flag == (fast - slow)){
        //printf("%d ", flag);
        slow = slow->next;
        fast = fast->next;
    }
    //printf("%d ", flag);
    if(!fast->next)
        return NULL;
    return fast;
}
/*

struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode *first=head,*sec;
    if(first==NULL)    return NULL;
    if(first->next==first)   return first;
    if(first->next==NULL)    return NULL;
    else
    {
        sec=first->next;
        int dou=sec-first;
        while(sec!=NULL && (sec-first)==dou)
        {
            first=first->next;
            sec=first->next;
        }
        if(sec==NULL)   return NULL;
        else
        {
            return sec;
        }
    }
}

*/
// @lc code=end

