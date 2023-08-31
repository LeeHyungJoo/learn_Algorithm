#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;

    int column_count = board[0].size();
    int row_count = board.size();

    vector<vector<bool>> board_check;
    board_check.resize(row_count);
    for (int i = 0; i < row_count; i++)
        board_check[i].resize(column_count, false);

    
    for (int i = 0; i < row_count; i++)
    {
        for (int j = 0; j < column_count; j++)
        {
            if (board[i][j] == 1)
            {
                board_check[i][j] = true;
                if (j > 0)
                {
                    board_check[i][j - 1] = true;
                }

                if (j < column_count - 1)
                {
                    board_check[i][j + 1] = true;
                }

                if (i > 0)
                {
                    board_check[i - 1][j] = true;
                    if (j > 0)
                    {
                        board_check[i - 1][j - 1] = true;
                    }

                    if (j < column_count - 1)
                    {
                        board_check[i - 1][j + 1] = true;
                    }
                }

                if (i < row_count - 1)
                {
                    board_check[i + 1][j] = true;
                    if (j > 0)
                    {
                        board_check[i + 1][j - 1] = true;
                    }

                    if (j < column_count - 1)
                    {
                        board_check[i + 1][j + 1] = true;
                    }
                }
            }
        }
    }

    for (auto row : board_check)
    {
        for (auto col : row)
        {
            if (!col)
                answer++;
        }
    }


    return answer;
}