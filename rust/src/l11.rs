pub fn max_area(height: Vec<i32>) -> i32 {
    fn water(height: &Vec<i32>, l: usize, r: usize) -> i32 {
        (*height)[r].min((*height)[l]) * (r - l) as i32
    }
    let mut l = 0;
    let mut r = height.len() - 1;
    let mut res = water(&height, l, r);
    while l < r {
        if height[l] < height[r] {
            l += 1;
        } else {
            r -= 1;
        }
        res = res.max(water(&height, l, r));
    }
    res
}
