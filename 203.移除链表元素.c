/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
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
没过
*/
// struct ListNode* removeElements(struct ListNode* head, int val){
//     struct ListNode *p, *tmp;
//     if(!head)
//         return NULL;
//     while(head->val == val){
//         head = head->next;
//     }
//     p = head;
//     if(!p)
//         return NULL;
//     while(p->next){
//         if(val == p->next->val){
//             //删除节点
//             tmp = p->next;
//             p->next = tmp->next;
//         }
//         else
//             p = p->next;
//     }
//     return head;
// }

/*
思路：递归
*/
/*
struct ListNode* removeElements(struct ListNode* head, int val){ 
    if (head == NULL) {
        return NULL;
    }     

    // 删除 head 节点后面值为 val 的元素的链表
    struct ListNode* res = removeElements(head->next, val);
    // head 节点是要删除的节点
    if (head->val == val) {
        return res;
    } else {
        head->next = res;
        return head;
    }
}
*/

// @lc code=end

