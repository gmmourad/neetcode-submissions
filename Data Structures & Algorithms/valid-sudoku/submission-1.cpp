class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        std::unordered_set<char> board_0_seen{};
        std::unordered_set<char> board_1_seen{};
        std::unordered_set<char> board_2_seen{};
        std::vector<std::vector<char>> row_seen(9);
        std::vector<std::vector<char>> col_seen(9);
        for (size_t row=0; row<9; row++)
        {
            int curr_board= {};
            if (row !=0 && row%3 == 0)
            {
                board_0_seen.clear();
                board_1_seen.clear();
                board_2_seen.clear();
            }
            for (size_t col=0; col<9; col++)
            {
                char curr_val = board[row][col];
    
                if (col!=0 && col%3 ==0)
                {
                    curr_board++;
                }
                if (curr_val == '.')
                {
                    continue;
                }
                if (curr_board == 0 && board_0_seen.find(curr_val) != board_0_seen.end())
                {
                    return false;
                }
                else if (curr_board ==0 && board_0_seen.find(curr_val) ==board_0_seen.end())
                {
                    board_0_seen.insert(curr_val);
                }      
                if (curr_board == 1 && board_1_seen.find(curr_val) != board_1_seen.end())
                {
                    return false;
                }
                else if (curr_board ==1 && board_1_seen.find(curr_val) ==board_1_seen.end())
                {
                    board_1_seen.insert(curr_val);
                }
                if (curr_board == 2 && board_2_seen.find(curr_val) != board_2_seen.end())
                {
                    return false;
                }
                else if (curr_board ==2 && board_2_seen.find(curr_val) ==board_2_seen.end())
                {
                    board_2_seen.insert(curr_val);
                }
                if(std::find(row_seen[row].begin(), row_seen[row].end(), curr_val) != row_seen[row].end())
                {
                    return false;
                }
                else
                {
                    row_seen[row].push_back(curr_val);
                }
                if (std::find(col_seen[col].begin(), col_seen[col].end(),curr_val) != col_seen[col].end())
                {
                    return false;
                }
                else
                {
                    col_seen[col].push_back(curr_val);
                }
            }
        }
        return true;



    }
};
