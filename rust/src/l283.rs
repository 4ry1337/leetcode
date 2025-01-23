pub fn move_zeroes(nums: &mut Vec<i32>) {
    let mut zeros = 0;
    let mut index = 0;
    while index < nums.len() {
        if nums[index] == 0 {
            zeros += 1;
        }
    }
}
