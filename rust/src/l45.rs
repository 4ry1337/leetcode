fn jump(nums: Vec<i32>) -> i32 {
    let (mut furthest, mut current_end, mut jumps) = (0i32, 0i32, 0i32);
    for i in 0..nums.len() {
        furthest = furthest.max(i as i32 + nums[i]);
        if i as i32 == current_end {
            jumps += 1;
            current_end = furthest;
        }
    }
    return jumps;
}
