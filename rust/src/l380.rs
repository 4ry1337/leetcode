use rand::{thread_rng, Rng};
use std::collections::HashMap;

#[derive(Default)]
struct RandomizedSet {
    pub idx: HashMap<i32, usize>,
    pub vals: Vec<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {
    fn new() -> Self {
        Self::default()
    }

    fn insert(&mut self, val: i32) -> bool {
        if self.idx.contains_key(&val) {
            false
        } else {
            self.idx.insert(val, self.vals.len());
            self.vals.push(val);
            true
        }
    }

    fn remove(&mut self, val: i32) -> bool {
        if self.idx.contains_key(&val) {
            let index = self.idx[&val];
            let last_index = self.vals.len() - 1;

            self.vals[index] = self.vals[last_index];
            self.idx.insert(self.vals[last_index], index);

            self.idx.remove(&val);
            self.vals.pop();

            true
        } else {
            false
        }
    }

    fn get_random(&self) -> i32 {
        let mut rng = thread_rng();
        self.vals[rng.gen_range(0..self.vals.len())]
    }
}

/*
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */
