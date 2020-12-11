/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
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
先计算两个链表的长度，遍历短的那个，分别加到长的链表上。在判断超出的位。
注意点：
1.
tmp = (l3->val + l4->val + carry) % 10;
carry = (l3->val + l4->val + carry) / 10;
这里不能直接赋值给l3->val，因为这样下一行的l3->val就不是之前的值了
2.
l3 = p;
l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
l3 = l3->next;
这里要记得保留NULL之前的节点，也就是说链表在分配内存的时候一定只能给next分配，否则
如果给当前节点分配的话，地址变了前一个节点就指不到当前节点了
3.
几个卡点：
两个数一样长，有进位
两个数不一样长，长的一个数最高位有进位
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int carry = 0, len1 = 0, len2 = 0, tmp;
    struct ListNode *l3, *l4, *p, *ret;
    p = l1;
    while(p){
        len1++;
        p = p->next;
    }
    p = l2;
    while(p){
        len2++;
        p = p->next;
    }
    l3 = (len1 >= len2) ? l1 : l2;
    l4 = (len1 < len2) ? l1 : l2;
    ret = l3;
    while(l4){
        //printf("%d %d %d", l3->val, l4->val, carry);
        tmp = (l3->val + l4->val + carry) % 10;
        carry = (l3->val + l4->val + carry) / 10;
        l3->val = tmp;
        p = l3;
        l3 = l3->next;
        l4 = l4->next;
    }
    
    if(carry != 0){
        while(l3){
            //printf("%d %d", l3->val, carry);
            tmp = (l3->val + carry) % 10;
            carry = (l3->val + carry) / 10;
            l3->val = tmp;
            if(l3->next == NULL)
                p = l3;
            l3 = l3->next;
        }
        if(carry != 0){
            l3 = p;
            l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            if(l3->next == NULL)
                return 0;
            l3 = l3->next;
            l3->val = carry;
            l3->next = NULL;
            //printf("%d %d", l3->val, carry);
        }
    }
    return ret;
}


// @lc code=end

