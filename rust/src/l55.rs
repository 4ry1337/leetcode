fn can_jump(nums: Vec<i32>) -> bool {
    let mut max_jump = 0i32;
    for i in 0..nums.len() {
        if i as i32 > max_jump {
            return false;
        }
        max_jump = max_jump.max(nums[i] + i as i32);
    }
    return true;
}
