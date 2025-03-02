class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rw = new boolean[9][10];
        boolean[][] clm = new boolean[9][10];
        boolean[][] blk = new boolean[9][10];
        for(int i = 0 ; i < 9 ; i ++){
            for(int j = 0 ; j < 9 ; j ++){
                System.out.print(board[i][j] + " ");
                if(board[i][j] == '.') continue ;
                int dg = board[i][j] - '0';
                if(!rw[i][dg] && !clm[j][dg] && !blk[(i / 3) * 3 + (j / 3)][dg]){
                    blk[(i / 3) * 3 + (j / 3)][dg] = rw[i][dg] = clm[j][dg] = true ;
                }else return false ;
            }
            System.out.println();
        }
        return true ;
    }
}