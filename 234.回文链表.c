/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
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
思路：快慢指针
注意：
1.特判
只有一个节点或空链表的情况
有两个节点时相等的情况
*/
bool isPalindrome(struct ListNode* head){
    struct ListNode *fast, *slow, *pre, *p, *back, *tail;
    fast = slow = head;
    if(!head || !head->next)
        return true;
    if(head->next->next == NULL){
        if(head->val == head->next->val)
            return true;
        else
            return false;
    }
    //找中点
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        //slow为中点偏右
    }
    //断开后半段，反向
    p = slow;
    pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    tail = pre;
    pre->next = p;
    
    while(p->next){
        //pre p->back 2 pre<-p back
        back = p->next;
        p->next = pre;
        pre = p;
        p = back;
    }
    slow->next = NULL;
    tail = NULL;
    p->next = pre;
    while(p){
        if(p->val != head->val){
            return false;
        }
        p = p->next;
        head = head->next;
    }
    return true;
}


// @lc code=end

