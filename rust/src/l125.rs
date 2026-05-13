pub fn is_palindrome(s: String) -> bool {
    let bytes = s.as_bytes();
    let mut l = 0usize;
    let mut r = s.len().saturating_sub(1);

    while l < r {
        while l < r && !bytes[l].is_ascii_alphanumeric() {
            l = l.saturating_add(1);
        }
        while l < r && !bytes[r].is_ascii_alphanumeric() {
            r = r.saturating_sub(1);
        }
        if bytes[l].to_ascii_lowercase() != bytes[r].to_ascii_lowercase() {
            return false;
        }
        l = l.saturating_add(1);
        r = r.saturating_sub(1);
    }
    true
}
