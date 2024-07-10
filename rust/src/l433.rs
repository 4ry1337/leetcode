pub fn compress(chars: &mut Vec<char>) -> i32 {
    let mut index = 0;
    let mut res = 0;
    while index < chars.len() {
        let curr = chars[index];
        let mut count = 0;
        while index < chars.len() && chars[index] == curr {
            index += 1;
            count += 1;
        }
        chars[res] = curr;
        res += 1;
        if count > 1 {
            for c in count.to_string().chars() {
                chars[res] = c;
                res += 1;
            }
        }
    }
    res as i32
}
