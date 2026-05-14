pub fn max_profit(prices: Vec<i32>) -> i32 {
    let mut res = 0;
    let mut min = prices[0];
    for &p in &prices {
        res = res.max(p - min);
        min = min.min(p);
    }
    res
}
