use std::collections::HashSet;

pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
    let ns = nums.into_iter().collect::<HashSet<i32>>();
    let mut res = 0;
    for &n in &ns {
        let mut curr = n;
        if ns.contains(&(curr - 1)) {
            continue;
        }
        while ns.contains(&curr) {
            curr += 1;
        }
        res = res.max(curr - n);
    }
    return res;
}
