/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
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
思路：双指针法。pa遍历完了从B开始遍历
注意：
1. 
在判断时只能用 pa==NULL 而不是 pa->next==NULL ,否则pa、pb不能同时到NULL点。
这题也说明，所有的NULL指向的地址是一样的。
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pa, *pb;
    // if(!headA || !headB)
    //     return NULL;
    pa = headA;
    pb = headB;
    while(pa != pb){
        if(!pa)
            pa = headB;
        else
            pa = pa->next;
        if(!pb)
            pb = headA;
        else
            pb = pb->next;
    }
    return pa;
}
// @lc code=end

