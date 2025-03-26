/*
 * @lc app=leetcode.cn id=232 lang=rust
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#[allow(dead_code)]
struct MyQueue {
    __push: Vec<i32>,
    __pop: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyQueue {
    #[allow(dead_code)]
    fn new() -> Self {
        return MyQueue {
            __push: Vec::new(),
            __pop: Vec::new(),
        };
    }

    #[allow(dead_code)]
    fn transfer_to_push(&mut self) {
        while self.__pop.len() > 0 {
            self.__push.push(self.__pop.pop().unwrap());
        }
    }

    #[allow(dead_code)]
    fn transfer_to_pop(&mut self) {
        while self.__push.len() > 0 {
            self.__pop.push(self.__push.pop().unwrap());
        }
    }

    #[allow(dead_code)]
    fn push(&mut self, x: i32) {
        if self.__pop.len() != 0 {
            self.transfer_to_push();
        }
        self.__push.push(x);
    }

    #[allow(dead_code)]
    fn pop(&mut self) -> i32 {
        if self.__push.len() != 0 {
            self.transfer_to_pop();
        }
        return self.__pop.pop().unwrap();
    }

    #[allow(dead_code)]
    fn peek(&mut self) -> i32 {
        if self.__push.len() != 0 {
            self.transfer_to_pop();
        }
        return self.__pop[self.__pop.len() - 1];
    }

    #[allow(dead_code)]
    fn empty(&self) -> bool {
        return self.__push.len() == 0 && self.__pop.len() == 0;
    }
}

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * let obj = MyQueue::new();
//  * obj.push(x);
//  * let ret_2: i32 = obj.pop();
//  * let ret_3: i32 = obj.peek();
//  * let ret_4: bool = obj.empty();
//  */
// @lc code=end
