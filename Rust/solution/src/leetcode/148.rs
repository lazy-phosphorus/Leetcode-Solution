/*
 * @lc app=leetcode.cn id=148 lang=rust
 *
 * [148] 排序链表
 */

#[derive(PartialEq, Eq, Clone, Debug)]
#[allow(dead_code)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    #[allow(dead_code)]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[allow(dead_code)]
struct Solution {}
// @lc code=start
use std::collections::BinaryHeap;

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl ListNode {
    #[inline]
    #[allow(dead_code)]
    fn new2(val: i32, next: Option<Box<ListNode>>) -> Self {
        ListNode { next, val }
    }
}

// Python 堆排序（列表实现）超时，难绷
// 换 Rust 用堆排序给你扬咯
impl Solution {
    #[allow(dead_code)]
    pub fn sort_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        if head.is_none() {
            return None;
        }

        let mut p = head;
        let mut heap: BinaryHeap<i32> = BinaryHeap::new();
        while let Some(node) = p {
            heap.push(node.val);
            p = node.next;
        }

        let mut result: Option<Box<ListNode>> = None;
        while heap.len() > 0 {
            result = Some(Box::new(ListNode::new2(heap.pop()?, result)));
        }

        return result;
    }
}
// @lc code=end
