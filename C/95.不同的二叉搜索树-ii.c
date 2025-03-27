/*
 * @lc app=leetcode.cn id=95 lang=c
 *
 * [95] 不同的二叉搜索树 II
 */

#include <malloc.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct __LinkedListNode {
    struct TreeNode *value;
    struct __LinkedListNode *next;
} LinkedListNode;

typedef struct __Result {
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;
} Result;

static void result_init(Result *this) {
    this->size = 0;
    this->head = NULL;
    this->tail = NULL;
}

static void result_push(Result *this, struct TreeNode *value) {
    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    node->value = value;
    node->next = NULL;
    if (this->size == 0)
        this->head = node;
    else
        this->tail->next = node;
    this->tail = node;
    this->size++;
}

// 不做边界检查
static struct TreeNode *result_pop(Result *this) {
    LinkedListNode *temp = this->head;
    struct TreeNode *value = this->head->value;
    this->head = this->head->next;
    this->size--;
    if (this->size == 0) {
        this->head = NULL;
        this->tail = NULL;
    }
    free(temp);
    return value;
}

static struct TreeNode **result_convert(Result *this) {
    struct TreeNode **array =
        (struct TreeNode **)calloc(this->size, sizeof(struct TreeNode *));
    int n = this->size;
    for (int i = 0; i < n; i++) {
        array[i] = result_pop(this);
    }
    return array;
}

static struct TreeNode *tree_node_new(int value) {
    struct TreeNode *this = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    this->left = NULL;
    this->right = NULL;
    this->val = value;
    return this;
}

static void tree_node_free(struct TreeNode *this) {
    if (this == NULL) return;

    tree_node_free(this->left);
    tree_node_free(this->right);
    tree_node_free(this);
}

static struct TreeNode *tree_node_clone(struct TreeNode *this) {
    if (this == NULL) return NULL;
    struct TreeNode *clone = tree_node_new(this->val);
    clone->left = tree_node_clone(this->left);
    clone->right = tree_node_clone(this->right);
    return clone;
}

// 仅对深拷贝后对象的右子树插入
static bool recurse(struct TreeNode *node, int i, int level, int n) {
    if (node == NULL) {
        return false;
    }

    if (i < level)
        return recurse(node->right, i + 1, level, n);
    else if (node->right == NULL) {
        node->right = tree_node_new(n);
    } else {
        struct TreeNode *temp = tree_node_new(n);
        temp->left = node->right;
        node->right = temp;
    }
    return true;
}

// Rust 确实不适合链表，这下明白了
struct TreeNode **generateTrees(int n, int *returnSize) {
    int size = 0, capacity = 16;
    Result result;

    result_init(&result);

    result_push(&result, tree_node_new(1));
    result_push(&result, NULL);

    for (int i = 2; i <= n; i++) {
        struct TreeNode *temp = result_pop(&result);
        while (temp != NULL) {
            struct TreeNode *clone = tree_node_clone(temp);
            int j = 0;
            while (recurse(clone, 0, j, i)) {
                result_push(&result, clone);
                j++;
                clone = tree_node_clone(temp);
            };

            struct TreeNode *new_root = tree_node_new(i);
            new_root->left = clone;
            result_push(&result, new_root);
            temp = result_pop(&result);
        }
        result_push(&result, NULL);
    }

    *returnSize = result.size - 1;
    return result_convert(&result);
}
// @lc code=end
