/*
 * @lc app=leetcode.cn id=23 lang=c
 *
 * [23] 合并 K 个升序链表
 */

#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

static struct ListNode *merge2lists(struct ListNode *left,
                                    struct ListNode *right) {
    struct ListNode *cache = NULL, *l_parent = NULL, *head = left;
    if (left == NULL) return right;
    while (left != NULL && right != NULL) {
        if (left->val < right->val) {
            l_parent = left;
            left = left->next;
            continue;
        } else {
            cache = left;
            left = right;
            right = right->next;
            left->next = cache;
            if (l_parent != NULL)
                l_parent->next = left;
            else
                head = left;
        }
    }
    if (right != NULL && l_parent != NULL) l_parent->next = right;
    return head;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) return NULL;

    while (listsSize > 1) {
        for (int i = 0; i < listsSize - 1; i++) {
            lists[i] = merge2lists(lists[i], lists[listsSize - 1]);
            listsSize--;
        }
    }
    return lists[0];
}
// @lc code=end
