pub fn merge_alternately(word1: String, word2: String) -> String {
    let mut result = String::new();
    let mut word1 = word1.chars().peekable();
    let mut word2 = word2.chars().peekable();
    while word1.peek().is_some() || word2.peek().is_some() {
        if let Some(c) = word1.peek() {
            result.push(c.clone());
            word1.next();
        }
        if let Some(c) = word2.peek() {
            result.push(c.clone());
            word2.next();
        }
    }
    result
}
