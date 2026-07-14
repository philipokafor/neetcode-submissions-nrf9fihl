class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            if(existsDupRow(board[i])){
                return false;
            }
            if(existsDupCol(board, i)){
                return false;
            }
            for(int row = 0; row < board.size(); row += 3){
                for(int col = 0; col < board.size(); col += 3){
                    if(existsDupBox(board, row, col)){
                        return false;
                    }
                }
            }
        }    
        return true;
    }

    bool existsDupRow(vector<char>& row){
        set<int> seenNums;
        int totalNums = 0;
        for(int i = 0; i < row.size(); i++){
            if(row[i] == '.'){
                continue;
            }
            totalNums++;
            seenNums.insert(row[i]);
        }
        if(totalNums > seenNums.size()){
            return true;
        }
        return false;
    }

    bool existsDupCol(vector<vector<char>>& board, int col){
        set<int> seenNums;
        int totalNums = 0;
        for(int i = 0; i < 9; i++){
            if(board[i][col] == '.'){
                continue;
            }
            totalNums++;
            seenNums.insert(board[i][col]);
        }
        if(totalNums > seenNums.size()){
            return true;
        }
        return false;
    }

    // origin is top left corner of 3x3 box
    bool existsDupBox(vector<vector<char>>& board, int row, int col){
        set<int> seenNums;
        int totalNums = 0;
        for(int i = row; i < row + 3; i++){
            for(int j = col; j < col + 3; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                totalNums++;
                seenNums.insert(board[i][j]);
            }
        }
        if(totalNums > seenNums.size()){
            return true;
        }
        return false;
    }
};
