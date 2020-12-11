/*
 * @lc app=leetcode.cn id=143 lang=c
 *
 * [143] 重排链表
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
思路：快慢指针找中点，后半段链表反转，在左右各取一个合并。
*/
void reorderList(struct ListNode* head){
    struct ListNode *mid, *tail, *p, *pre, *back, *tmp, *pHead;
    mid = tail = head;
    
    //特判
    if(!head || !head->next ||!head->next->next)
        return;
    
    //找中点
    while(tail && tail->next){
        mid = mid->next;
        tail = tail->next->next;
    }//mid奇数在中点，偶数在中点偏右

    //反转后半段
    // 两种情况
    // pre->p->NUll
    // pre->p->back
    p = mid;
    mid->next = pre = NULL;
    while(p){
        printf("%d ", p->val);
        p = p->next;
    }
    p = head;
    while(p){
        printf("%d ", p->val);
        p = p->next;
    }
    // while(p){
    //     //情况一
    //     if(!p->next){
    //         p->next = pre;
    //         break;
    //     }
    //     //情况二
    //     else{
    //         back = p->next;
    //         p->next = pre;
    //         pre = p;
    //         p = back;
    //     }
    // }//p为表头
    // while(p){
    //     printf("%d ", p->val);
    //     p = p->next;
    // }
    // p = head;
    // while(p){
    //     printf("%d ", p->val);
    //     p = p->next;
    // }

    // //合并两个链表
    // pHead = head;
    // while(p && head){
    //     tmp = head->next;
    //     head->next = p;
    //     p->next = tmp;
    //     p = p->next;
    //     head = tmp;
    // }
    // p = pHead;
    // while(p){
    //     printf("%d ", p->val);
    //     p = p->next;
    // }
    return;
}
// @lc code=end

