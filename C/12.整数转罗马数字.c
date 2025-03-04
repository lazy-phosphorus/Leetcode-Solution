/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

#include <malloc.h>
#include <stddef.h>
#include <string.h>

// @lc code=start
char *intToRoman(int num) {
    char *result = calloc(20, sizeof(char));
    char ten = 'X', five = 'V', one = 'I';
    int p = 18;

    result[19] = '\0';

    for (int i = 0; i < 3; i++) {
        int times = num % 10;
        if (times == 9) {
            result[p] = ten;
            result[p - 1] = one;
            p -= 2;
        } else {
            while (times > 5) {
                result[p] = one;
                p--;
                times--;
            }
            if (times == 5) {
                result[p] = five;
                p--;
                times -= 5;
            }
            if (times == 4) {
                result[p] = five;
                result[p - 1] = one;
                p -= 2;
                times -= 4;
            }
            while (times > 0) {
                result[p] = one;
                p--;
                times--;
            }
        }
        num = num / 10;

        if (i == 0) {
            ten = 'C';
            five = 'L';
            one = 'X';
        }
        if (i == 1) {
            ten = 'M';
            five = 'D';
            one = 'C';
        }
    }

    while (num > 0) {
        result[p] = ten;
        p--;
        num--;
    }
    memmove(result, result + p + 1, sizeof(char) * (20 - p - 1));

    return result;
}
// @lc code=end
