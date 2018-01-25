//
//  206_Reverse_Linked_List.h
//  Algorithm
//
//  Created by lidahe on 2018/1/25.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef _06_Reverse_Linked_List_h
#define _06_Reverse_Linked_List_h

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/description/
//
// 递归的方式反转链表
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        // 递归终止条件
        ListNode* pre = NULL;
        ListNode *cur = head;
        while(cur != NULL) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
}

#endif /* _06_Reverse_Linked_List_h */
