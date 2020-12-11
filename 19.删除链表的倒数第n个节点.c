/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第N个节点
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
将倒数的节点转换为正数的节点操作
注意点：
1.
转化成正数的来求
2.
注意删除第一个节点的时候单独判断

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 0, n1;
    struct ListNode *p = head;
    while(p){
        len++;
        p = p->next;
    }
    //printf("%d", len);
    //正数第n个
    n1 = len - n;
    //printf("%d", n1);
    p = head;
    if(n1 == 0)
        return head->next;
    for (int i = 0; i < n1 - 1; i++)
        p = p->next;
    p->next = p->next->next;
    return head;
}
*/
/* 方法二：快慢指针
思路：最终状态两个指针的位置不同，后指针的位置在待删除的节点的前一个，前指针的位置在NULL。
当n<0时，前指针比后指针快n+1位，这个是最常规的状态。
当n=0时，待删除的节点时头结点，返回head->next即可。
不存在n>0的情况

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    while(p){
        if(n<0){
            q = q->next;
        }
        n--;
        p = p->next;
    }
    if(n==0){
        return head->next;
    }
    q->next = q->next->next;
    return head;
}
*/
// @lc code=end

