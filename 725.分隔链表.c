/*
 * @lc app=leetcode.cn id=725 lang=c
 *
 * [725] 分隔链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
//     struct ListNode *p = root, **res, **head;
//     int flag = 0;
//     res = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
//     for (int i = 0; i < k; i++){
//         res[i] = (struct ListNode *)malloc(sizeof(struct ListNode));
//         //res[i]->val = 0;
//         //res[i]->next = NULL;
//     }
//     head = res;
    
//     while(p){
//         res[flag % k]->next = (struct ListNode *)malloc(sizeof(struct ListNode));
//         res[flag % k]->next->val = p->val;
//         res[flag % k] = res[flag % k]->next;
        
//         //printf("%d", res[flag % k]->val);
//         p = p->next;
//         flag++;
//     }

//     for (int i = 0; i < k; i++){
//         res[i]->next = NULL;
//     }
//     p = head[0];
//     while(p){
//         printf("%d", p->val);
//         p = p->next;
//     }
//     *returnSize = k;
//     return head;
// }

/*
思路：计算总长度；确定每组的长度；开始打断链表
注意：
1.
打断链表时，直接赋表头就行，不用每个节点从新分配
2.
当链表分配完了但是grp不为0，则后续链表都为NULL
*/
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    struct ListNode **res, *p = root, *tmp;
    int len = 0, grp[k], i;
    res = (struct ListNode **)malloc(sizeof(struct ListNode *) * k);
    //计算总长度
    while(p){
        len++;
        p = p->next;
    }
    //确定每组的长度
    for (int i = 0; i < k; i++){
        if(i < len % k){
            grp[i] = len / k;
        }
        else{
            grp[i] = len / k - 1;
        }
    }
    //开始打断链表
    p = root;
    for (i = 0; i < k; i++){
        res[i] = p;
        while(p && grp[i]){
            grp[i]--;
            p = p->next;
        }
        if(p){
            tmp = p->next;
            p->next = NULL;
            p = tmp;
        }
        else{
            break;
        }
    }
    if(i != k){
        for (; i < k; i++){

            res[i] = NULL;
        }
    }
    *returnSize = k;
    return res;
}
 
// @lc code=end

