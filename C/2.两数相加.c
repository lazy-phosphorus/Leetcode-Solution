/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */
#include <malloc.h>
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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    int added = 0;
    struct ListNode *result =
                        (struct ListNode *)malloc(sizeof(struct ListNode)),
                    *p = result;

    while (l1 != NULL && l2 != NULL) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));

        p->next->val = (l1->val + l2->val + added) % 10;
        added = (l1->val + l2->val + added) / 10;

        l1 = l1->next;
        l2 = l2->next;
        p = p->next;
    }

    while (l1 != NULL) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = (added + l1->val) % 10;
        added = (added + l1->val) / 10;
        l1 = l1->next;
        p = p->next;
    }
    while (l2 != NULL) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = (added + l2->val) % 10;
        added = (added + l2->val) / 10;
        l2 = l2->next;
        p = p->next;
    }

    if (added != 0) {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->val = added;
        p->next->next = NULL;
    } else
        p->next = NULL;

    p = result;
    result = result->next;
    free(p);

    return result;
}
// @lc code=end
