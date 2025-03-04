/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 */

#include <malloc.h>
#include <stdbool.h>
#include <string.h>

// @lc code=start

bool wordBreak(char *s, char **wordDict, int wordDictSize) {
    int p = 0, word_length = 0, s_length = strlen(s);
    bool result = false, *checked = (bool *)calloc(s_length + 1, sizeof(bool));

    checked[s_length] = true;

    for (int i = s_length - 1; i >= 0; i--) {
        if (!checked[i + 1]) continue;

        for (int j = 0; j < wordDictSize; j++) {
            word_length = strlen(wordDict[j]);
            p = word_length - 1;

            if (i < p) continue;
            while (p >= 0) {
                if (s[i - word_length + 1 + p] != wordDict[j][p]) break;
                p--;
            }

            if (p == -1) checked[i - word_length + 1] = true;
        }
    }

    result = checked[0];
    free(checked);
    return result;
}
// @lc code=end
