fn h_index(citations: Vec<i32>) -> i32 {
    let length = citations.len();
    let mut freq = vec![0; length + 1];
    for &citation in &citations {
        freq[std::cmp::min(citation as usize, length)] += 1;
    }
    let mut res = 0;
    for h in (0..=length).rev() {
        res += freq[h];
        if res >= h {
            return res as i32;
        }
    }
    0i32
}
/*
1 3 1
0 0 0 0
0 2 0 1
0 1 2 3
3 <= 1


*/
fn main() {
    println!("{}", h_index(vec![1, 3, 1]));
}
