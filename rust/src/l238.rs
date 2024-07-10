pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
    let mut prefix = 1;
    let mut suffix = 1;
    let mut res = vec![1; nums.len()];
    for i in 0..nums.len() {
        let left = i;
        let right = (nums.len() - 1) - i;
        res[left] *= prefix;
        res[right] *= suffix;
        prefix *= nums[left];
        suffix *= nums[right];
    }
    res
}
