pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
    let mut rows = vec![0; 9];
    let mut cols = vec![0; 9];
    let mut cells = vec![0; 9];
    for x in 0..9 {
        for y in 0..9 {
            if board[x][y] == '.' {
                continue;
            }
            let value = board[x][y] as i32 - '1' as i32;
            let bits = 1 << value;
            let cell_id = (x / 3) * 3 + (y / 3);
            if (rows[x] & bits) != 0 || (cols[y] & bits) != 0 || (cells[cell_id] & bits) != 0 {
                return false;
            }
            rows[x] |= bits;
            cols[y] |= bits;
            cells[cell_id] |= bits;
        }
    }
    true
}
