/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
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
同步遍历两个链表，小的节点加入到新链表中
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p, *head;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = head;
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    while (l1 && l2){
        if(l1->val < l2->val){
            p->next = l1;
            l1 = l1->next;
        }
        else{
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if(l1)
        p->next = l1;
    if(l2)
        p->next = l2;
    return head->next;
}
/*
p->next = t, next在左边表示p指向t，即p的下一个结点是t
p = p->next, next在右边表示p移动到下一个结点上
*/
/*方法二.递归
函数 mergeTwoLists(l1, l2) 的作用是返回重排序、合并后的l1, l2。
所以可以不断的划分小任务，接受返回值。

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1)
		return l2;
	if (!l2)
		return l1;
	if (l1->val < l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}
*/

// @lc code=end

