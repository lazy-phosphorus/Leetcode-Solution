/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <limits.h>
#include <stdbool.h>
#include <string.h>

// @lc code=start
int myAtoi(char *s) {
    size_t length = strlen(s);
    int i = 0;
    long long int result = 0;
    bool negative_flag = false;

    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '-') {
        negative_flag = true;
        i++;
    } else if (s[i] == '+')
        i++;
    else if (!('0' <= s[i] && s[i] <= '9'))
        return 0;

    while ('0' <= s[i] && s[i] <= '9') {
        result = result * 10 + s[i] - '0';
        if (result > INT_MAX && !negative_flag) return INT_MAX;
        if (-result < INT_MIN && negative_flag) return INT_MIN;
        i++;
    }

    if (result > INT_MAX && !negative_flag) return INT_MAX;
    return negative_flag ? -result : result;
}
// @lc code=end
