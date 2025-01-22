pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
    let mut result = vec![false; candies.len()];
    let max = candies.iter().max().unwrap().clone();
    for i in 0..candies.len() {
        if candies[i] + extra_candies >= max {
            result[i] = true;
        }
    }
    result
}
