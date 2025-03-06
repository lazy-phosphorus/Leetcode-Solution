#
# @lc app=leetcode.cn id=427 lang=python3
#
# [427] 建立四叉树
#


# @lc code=start
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
from math import floor
from typing import Self, List, Optional


class Node:
    def __init__(
        self,
        val: bool,
        isLeaf: bool,
        topLeft: Optional[Self],
        topRight: Optional[Self],
        bottomLeft: Optional[Self],
        bottomRight: Optional[Self],
    ):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight


class Solution:
    def recurse(
        self,
        grid: List[List[int]],
        from_row: int,
        from_col: int,
        to_row: int,
        to_col: int,
    ) -> Node:
        result = Node(False, False, None, None, None, None)
        if from_row + 1 == to_row:
            result.val = grid[from_row][from_col] == 1
            result.isLeaf = True
            return result

        result.topLeft = self.recurse(
            grid,
            from_row,
            from_col,
            floor((from_row + to_row) / 2),
            floor((from_col + to_col) / 2),
        )
        result.topRight = self.recurse(
            grid,
            from_row,
            floor((from_col + to_col) / 2),
            floor((from_row + to_row) / 2),
            to_col,
        )
        result.bottomLeft = self.recurse(
            grid,
            floor((from_row + to_row) / 2),
            from_col,
            to_row,
            floor((from_col + to_col) / 2),
        )
        result.bottomRight = self.recurse(
            grid,
            floor((from_row + to_row) / 2),
            floor((from_col + to_col) / 2),
            to_row,
            to_col,
        )

        if (
            result.topLeft.isLeaf
            and result.topRight.isLeaf
            and result.bottomLeft.isLeaf
            and result.bottomRight.isLeaf
        ):
            if (
                result.topLeft.val
                and result.topRight.val
                and result.bottomLeft.val
                and result.bottomRight.val
            ):
                result.isLeaf = True
                result.val = True
                result.topLeft = None
                result.topRight = None
                result.bottomLeft = None
                result.bottomRight = None
            elif not (
                result.topLeft.val
                or result.topRight.val
                or result.bottomLeft.val
                or result.bottomRight.val
            ):
                result.isLeaf = True
                result.val = False
                result.topLeft = None
                result.topRight = None
                result.bottomLeft = None
                result.bottomRight = None

        return result

    def construct(self, grid: List[List[int]]) -> Node:
        return self.recurse(grid, 0, 0, len(grid), len(grid[0]))


# @lc code=end
