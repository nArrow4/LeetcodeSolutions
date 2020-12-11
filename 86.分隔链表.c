/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
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
重开两个链表，分别存放小和大于等于x的数，最后再合并
注意点：
1. 
在判断小链表或大链表为空时要判断p1->next == NULL，
不能直接判断p1
*/
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *p, *p1, *p2, *head1, *head2;
    if(!head)
        return NULL;
    p = head;
    p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    p2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    head1 = p1;
    head2 = p2;
    p1->next = NULL;
    p2->next = NULL;
    while(p){
        if(p->val < x){
            p1->next = p;
            p1 = p1->next;
        }
        else{
            p2->next = p;
            p2 = p2->next;
        }
        p = p->next;
    }
    if(p1 && p2){
        //head1->...->p1
        //head2->...->p2
        p1->next = head2->next;
        p2->next = NULL;
        return head1->next;
    }
    else if(p1 && !p2->next){
        //head1->...->p1
        //head2(p2)
        p1->next = NULL;
        return head1->next;
    }
    else if(!p1->next && p2){
        //head2->...->p2
        //head1(p1)
        p2->next = NULL;
        return head2->next;
    }
    return head1->next;
}

// @lc code=end

