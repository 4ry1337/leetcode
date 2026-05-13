pub fn trap(height: Vec<i32>) -> i32 {
    let mut res = 0;

    let mut l = 0;
    let mut lh = height[l];
    let mut r = height.len() - 1;
    let mut rh = height[r];
    while l < r {
        if lh < rh {
            l += 1;
            lh = lh.max(height[l]);
            res += lh - height[l];
        } else {
            r -= 1;
            rh = rh.max(height[r]);
            res += rh - height[r];
        }
    }
    res
}
