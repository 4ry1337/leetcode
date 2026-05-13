pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut nums = nums.clone();
    nums.sort();
    let mut res = vec![];
    let n = nums.len();
    for i in 0..(n - 2) {
        if i > 0 && nums[i] == nums[i - 1] {
            continue;
        }
        let mut l = i + 1;
        let mut r = n - 1;
        while l < r {
            let three_sum = nums[i] + nums[l] + nums[r];
            if three_sum == 0 {
                res.push(vec![nums[i], nums[l], nums[r]]);
                while l < r && nums[l] == nums[l + 1] {
                    l += 1;
                }
                while l < r && nums[r] == nums[r - 1] {
                    r -= 1;
                }
                r -= 1;
                l += 1;
            } else if three_sum < 0 {
                l += 1;
            } else {
                r -= 1;
            }
        }
    }
    res
}
