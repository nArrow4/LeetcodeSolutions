/*
 * @lc app=leetcode.cn id=82 lang=c
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *pre, *cur, *p;
    int cnt = 0;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = head;
    //空表直接返回
    if(!head)
        return NULL;
    pre = p;
    cur = p->next;
    //只有一个元素，直接返回
    if(!head->next)
        return head;
    while(cur){
        if(pre->val != cur->val){
            cnt++;
            //大小不同，快指针向后遍历
            while(cur->next){
                if(cur->val != cur->next->val){
                    if(cnt>1){
                        cur = cur->next;
                        cnt = 0;
                    }
                    break;
                }
                else
                    cnt++;
            }
            //跳过重复节点
            pre->next = cur;
            pre = pre->next;
            if(cur->next)
                cur = cur->next;
        }
    }
    return p->next;
}


// @lc code=end

