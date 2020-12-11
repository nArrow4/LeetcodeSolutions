/*
 * @lc app=leetcode.cn id=24 lang=c
 *
 * [24] 两两交换链表中的节点
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
两个两个节点一起遍历
注意点：
1. 
链表为空的情况
2. 
增加一个头指针更方便
*/
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *fir, *sec, *pre, *tmp;
    if(!head)
        return NULL;
    fir = head;
    sec = head->next;
    pre = (struct ListNode*)malloc(sizeof(struct ListNode));
    pre->next = fir;
    head = pre;
    //pre->fir->sec->next
    while(sec != NULL){
        //if(sec->next == NULL || pre->next == NULL || sec == NULL)
            //
        pre->next = sec;
        fir->next = sec->next;
        sec->next = fir;
        tmp = fir;
        fir = sec;
        sec = tmp;
        pre = sec;

        if(sec->next && sec->next->next){
            fir = fir->next->next;
            sec = sec->next->next;
        }
        else
            break;
    }
    return head->next;
}


// @lc code=end

