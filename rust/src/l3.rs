use std::collections::{HashMap, HashSet};

pub fn length_of_longest_substring(s: String) -> i32 {
    let mut res = 0;

    let mut mp = HashMap::new();
    let mut l = 0;

    for (r, ch) in s.chars().enumerate() {
        if let Some(&prev) = mp.get(&ch)
            && prev >= l
        {
            l = prev + 1;
        }
        mp.insert(ch, r);
        res = res.max(r - l + 1);
    }

    res as i32
}

// pub fn length_of_longest_substring(s: String) -> i32 {
//     let mut substring = String::new();
//
//     let mut res = 0;
//
//     for ch in s.chars() {
//         if let Some(idx) = substring.find(ch) {
//             _ = substring.drain(..=idx);
//         }
//         substring.push(ch);
//         res = res.max(substring.len());
//     }
//
//     res as i32
// }
