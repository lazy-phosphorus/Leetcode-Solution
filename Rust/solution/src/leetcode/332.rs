/*
 * @lc app=leetcode.cn id=332 lang=rust
 *
 * [332] 重新安排行程
 */

#[allow(dead_code)]
struct Solution {}

// @lc code=start
use std::collections::{HashMap, HashSet};

#[allow(dead_code)]
struct Graph<'a> {
    str_to_index: HashMap<&'a String, usize>,
    index_to_str: Vec<&'a String>,
    nodes: Vec<Vec<i32>>,
    edge_quantity: i32,
}

impl<'a> Graph<'a> {
    #[allow(dead_code)]
    fn new() -> Self {
        return Graph {
            str_to_index: HashMap::new(),
            index_to_str: Vec::new(),
            nodes: Vec::new(),
            edge_quantity: 0,
        };
    }

    #[allow(dead_code)]
    fn add_node(&mut self, values: &'a HashSet<&'a String>) {
        for value in values {
            self.index_to_str.push(value);
        }
        self.index_to_str.sort();

        let mut i = 0;
        while i < self.index_to_str.len() {
            self.str_to_index.insert(self.index_to_str[i], i);
            let mut children = Vec::with_capacity(self.index_to_str.len());
            let mut j = 0;
            while j < self.index_to_str.len() {
                children.push(0);
                j += 1;
            }
            self.nodes.push(children);
            i += 1;
        }
    }

    #[allow(dead_code)]
    fn add_edge(&mut self, from: &'a String, to: &'a String) {
        let from_index = self.str_to_index.get(from).unwrap();
        let to_index = self.str_to_index.get(to).unwrap();

        self.nodes[*from_index][*to_index] += 1;
        self.edge_quantity += 1;
    }

    #[allow(dead_code)]
    fn dfs_recurse(&mut self, result: &mut Vec<usize>) -> bool {
        if result.len() == self.edge_quantity as usize + 1 {
            return true;
        }

        let from = result[result.len() - 1];
        let mut i = 0;
        while i < self.nodes[from].len() {
            if self.nodes[from][i] == 0 {
                i += 1;
                continue;
            }

            self.nodes[from][i] -= 1;
            result.push(i);
            if self.dfs_recurse(result) {
                return true;
            }
            result.pop();
            self.nodes[from][i] += 1;
            i += 1;
        }

        return false;
    }

    #[allow(dead_code)]
    fn dfs(&mut self) -> Vec<usize> {
        let mut result: Vec<usize> = Vec::new();

        let mut i = 0;
        while i < self.nodes.len() {
            if self.index_to_str[i] == "JFK" {
                break;
            }

            i += 1;
        }

        result.push(i);
        self.dfs_recurse(&mut result);

        return result;
    }
}

impl Solution {
    #[allow(dead_code)]
    pub fn find_itinerary(tickets: Vec<Vec<String>>) -> Vec<String> {
        let mut airports: HashSet<&String> = HashSet::new();
        let mut graph = Graph::new();

        for ticket in &tickets {
            airports.insert(&ticket[0]);
            airports.insert(&ticket[1]);
        }

        graph.add_node(&airports);

        for ticket in &tickets {
            graph.add_edge(&ticket[0], &ticket[1]);
        }

        return graph
            .dfs()
            .iter()
            .map(|v| (*graph.index_to_str[*v]).clone())
            .collect();
    }
}
// @lc code=end
