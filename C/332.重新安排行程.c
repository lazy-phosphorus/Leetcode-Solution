/*
 * @lc app=leetcode.cn id=332 lang=c
 *
 * [332] 重新安排行程
 */

#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct __Airport Airport;

typedef struct __List {
    struct __Airport *value;
    int quantity;
    struct __List *previous;
    struct __List *next;
} List;

static List *list_new(Airport *value) {
    List *this = (List *)malloc(sizeof(List));
    this->value = value;
    this->quantity = 0;
    this->next = NULL;
    this->previous = NULL;
    return this;
}

typedef struct __Airport {
    char *name;
    List *to;
} Airport;

static void airport_init(Airport *this, char *name) {
    this->name = name;
    this->to = NULL;
}

static void airport_release(Airport *this) {
    List *temp = this->to;
    while (temp != NULL) {
        this->to = temp->next;
        free(temp);
        temp = this->to;
    }
}

static void airport_add_child(Airport *this, Airport *child) {
    if (this->to == NULL) {
        this->to = list_new(child);
        this->to->quantity++;
        return;
    }

    List *p = this->to, *temp = NULL;
    while (p != NULL) {
        int cmp = strcmp(child->name, p->value->name);
        if (cmp < 0) {
            temp = list_new(child);
            temp->quantity++;
            temp->previous = p->previous;
            if (p->previous != NULL)
                p->previous->next = temp;
            else
                this->to = temp;
            p->previous = temp;
            temp->next = p;
            break;
        } else if (cmp == 0) {
            p->quantity++;
            break;
        }
        if (p->next == NULL) {
            p->next = list_new(child);
            p->next->quantity++;
            p->next->previous = p->next;
            break;
        }
        p = p->next;
    }
}

static void dfs(Airport *root, char ***result, int *result_capacity,
                int *result_size, int *ticketsSize) {
    List *p = root->to;
    if ((*result_size) == (*result_capacity)) {
        (*result_capacity) *= 2;
        (*result) =
            (char **)realloc(*result, (*result_capacity) * sizeof(char *));
    }
    (*result)[*result_size] = (char *)calloc(4, sizeof(char));
    memcpy((*result)[*result_size], root->name, sizeof(char) * 3);
    (*result)[*result_size][3] = '\0';
    (*result_size)++;

    if (*ticketsSize == 0) return;

    while (p != NULL) {
        if (p->quantity > 0) {
            p->quantity--;
            (*ticketsSize)--;
            dfs(p->value, result, result_capacity, result_size, ticketsSize);
            if (*ticketsSize == 0) return;
            (*ticketsSize)++;
            p->quantity++;
        }
        p = p->next;
    }
    (*result_size)--;
}

char **findItinerary(char ***tickets, int ticketsSize, int *ticketsColSize,
                     int *returnSize) {
    int array_size = 0, array_capacity = 64, root = 0, result_size = 0,
        result_capacity = 64;
    char **result = (char **)calloc(result_capacity, sizeof(char *));
    Airport *array = (Airport *)calloc(array_capacity, sizeof(Airport));

    for (int i = 0; i < ticketsSize; i++) {
        int from = -1, to = -1;
        for (int j = 0; j < array_size; j++) {
            if (strcmp(array[j].name, tickets[i][0]) == 0)
                from = j;
            else if (strcmp(array[j].name, tickets[i][1]) == 0)
                to = j;
        }

        if (from == -1) {
            if (array_size == array_capacity) {
                array_capacity *= 2;
                array =
                    (Airport *)realloc(array, array_capacity * sizeof(Airport));
            }
            airport_init(array + array_size, tickets[i][0]);
            from = array_size;
            array_size++;
        }
        if (to == -1) {
            if (array_size == array_capacity) {
                array_capacity *= 2;
                array =
                    (Airport *)realloc(array, array_capacity * sizeof(Airport));
            }
            airport_init(array + array_size, tickets[i][1]);
            to = array_size;
            array_size++;
        }

        airport_add_child(array + from, array + to);
    }

    for (int i = 0; i < array_size; i++) {
        if (strcmp("JFK", array[i].name) == 0) {
            root = i;
            break;
        }
    }

    dfs(array + root, &result, &result_capacity, &result_size, &ticketsSize);

    for (int i = 0; i < array_size; i++) {
        airport_release(array + i);
    }
    free(array);

    *returnSize = result_size;
    return result;
}
// @lc code=end
