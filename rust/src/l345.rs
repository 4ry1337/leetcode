pub fn reverse_vowels(s: String) -> String {
    let mut s: Vec<char> = s.chars().collect();
    let mut l = 0;
    let mut r = s.len() - 1;
    while l < r {
        if "aeiouAEIOU".contains(s[l]) {
            if "aeiouAEIOU".contains(s[r]) {
                s.swap(l, r);
                l += 1;
            }
            r -= 1;
        } else {
            l += 1;
        }
    }
    s.into_iter().collect()
}
