/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

#include <limits.h>
#include <math.h>
#include <stdbool.h>

// @lc code=start
int reverse(int x) {
    if (x == INT_MIN) return 0;

    bool minux_flag = x < 0, start_flag = false;
    unsigned long long int result = 0, index = 0, temp = 0;

    if (minux_flag)
        temp = -x;
    else
        temp = x;

    for (int i = (int)pow(10, 9); i >= 10; i /= 10) {
        if (temp / i != 0) {
            result += (int)pow(10, index) * (temp / i);
            index++;
            temp = temp % ((temp / i) * i);
            start_flag = true;
        } else if (start_flag) {
            result += (int)pow(10, index) * (temp / i);
            index++;
        }
    }

    result += (int)pow(10, index) * temp;
    if (result > INT_MAX) return 0;
    result = minux_flag ? -result : result;
    return result;
}
// @lc code=end
