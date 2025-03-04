/*
 * @lc app=leetcode.cn id=380 lang=c
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include <limits.h>
#include <malloc.h>
#include <memory.h>
#include <stdbool.h>

// @lc code=start

typedef struct {
    int **space;
    int *sizes;
    int size;
    int capacity;
    int *collision_capacity;
} RandomizedSet;

RandomizedSet *randomizedSetCreate() {
    RandomizedSet *this = (RandomizedSet *)malloc(sizeof(RandomizedSet));
    this->capacity = 1024;
    this->sizes = (int *)calloc(this->capacity, sizeof(int));
    this->space = (int **)calloc(this->capacity, sizeof(int *));
    this->collision_capacity = (int *)calloc(this->capacity, sizeof(int));
    this->size = 0;
    for (int i = 0; i < this->capacity; i++) {
        this->collision_capacity[i] = 5;
        this->sizes[i] = 0;
        this->space[i] =
            (int *)calloc(this->collision_capacity[i], sizeof(int));
    }
    return this;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    int mod = val & 1023;

    for (int i = 0; i < obj->sizes[mod]; i++) {
        if (obj->space[mod][i] == val) return false;
    }
    if (obj->sizes[mod] == obj->collision_capacity[mod]) {
        obj->collision_capacity[mod] *= 2;
        obj->space[mod] =
            realloc(obj->space + mod, obj->collision_capacity[mod]);
    }
    obj->space[mod][obj->sizes[mod]] = val;
    obj->sizes[mod]++;
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    int mod = val & 1023;

    for (int i = 0; i < obj->sizes[mod]; i++) {
        if (obj->space[mod][i] == val) {
            obj->space[mod][i] = obj->space[mod][obj->sizes[mod] - 1];
            obj->sizes[mod]--;
            obj->size--;
            return true;
        }
    }
    return false;
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    int cache = 0, rand2 = (rand() & INT_MAX) % obj->size;
    for (int i = 0; i < obj->capacity; i++) {
        if (obj->sizes[i] <= rand2)
            rand2 -= obj->sizes[i];
        else if (obj->sizes[i] > 0)
            return obj->space[i][rand2];
    }
    return 0;
}

void randomizedSetFree(RandomizedSet *obj) {
    for (int i = 0; i < obj->capacity; i++) {
        free(obj->space[i]);
    }
    free(obj->sizes);
    free(obj->space);
    free(obj->collision_capacity);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);

 * bool param_2 = randomizedSetRemove(obj, val);

 * int param_3 = randomizedSetGetRandom(obj);

 * randomizedSetFree(obj);
*/
// @lc code=end
