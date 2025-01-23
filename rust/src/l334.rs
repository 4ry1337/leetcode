pub fn increasing_triplet(nums: Vec<i32>) -> bool {
    let mut l = i32::MAX;
    let mut m = i32::MAX;
    for i in nums.iter() {
        if *i <= l {
            l = *i;
        } else if *i <= m {
            m = *i;
        } else {
            return true;
        }
    }
    false
}
