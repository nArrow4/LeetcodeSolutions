/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (49.71%)
 * Likes:    280
 * Dislikes: 0
 * Total Accepted:    86.4K
 * Total Submissions: 173.7K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
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
双指针遍历，用flag储存val
也可以只用一个指针判断相邻两个的val是不是相等
*/
/*
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head, *pre = head;
    if(p == NULL)
        return head;
    p = p -> next;
    int flag = head->val;
    while(p != NULL){
        if(flag != p->val){
            flag = p->val;
            p = p->next;
            pre = pre->next;
        }
        else{
            pre->next = p->next;
            p = p->next;
            if(p == NULL)
                break;
        }
    }
    return head;
}
*/
/*

struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head)
        return NULL;
    struct ListNode *ret, *cur;
    int last = head->val;
    cur = head;
    ret = head;
    //cur->next = NULL;
    head = head->next;
    while(head){
        if(head->val != last){
            last = head->val;
            cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = last;
            cur->next = NULL;
        }
        head = head->next;
    }
    cur->next = NULL;
    return ret;
}
*/
/*
思路：
快慢节点，比较大小，如果相等就删去快指针
*/
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *pre, *cur;
    pre = head;
    if(!head)
        return NULL;
    if(head->next)
        cur = head->next;
    else
        return head;
    while(cur){
        if(pre->val == cur->val){
            pre->next = cur->next;
            cur = cur->next;
        }
        else{
            if(!cur->next)
                break;
            else{
                pre = cur;
                cur = cur->next;
            }
        }
    }
    return head;
}
// @lc code=end

