/*
 * @lc app=leetcode.cn id=621 lang=c
 *
 * [621] 任务调度器
 */

#include <malloc.h>
#include <memory.h>

// @lc code=start
static inline int max(int a, int b) { return a > b ? a : b; }

int leastInterval(char *tasks, int tasksSize, int n) {
    int max_task = 0, max_task_num = 0, task_quantities[26];
    memset(task_quantities, 0, sizeof(int) * 26);
    for (int i = 0; i < tasksSize; i++) {
        task_quantities[tasks[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        max_task = max(task_quantities[i], max_task);
    }

    for (int i = 0; i < 26; i++) {
        if (task_quantities[i] == max_task) max_task_num++;
    }

    return max(tasksSize, (max_task - 1) * (n + 1) + max_task_num);
}
// @lc code=end
