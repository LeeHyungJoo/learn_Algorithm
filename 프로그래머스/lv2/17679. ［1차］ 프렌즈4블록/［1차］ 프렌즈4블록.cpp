#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int Delete2X2Tiles(int m, int n, unordered_map<int, unordered_map<int, pair<char, int>>>& board_arr)
{
    int delete_count = 0;
    for (int line = 0; line < m; line++)
    {
        auto& temp_line = board_arr[line];
        for (int caret = 0; caret < n; caret++)
        {
            const char& current_char = temp_line[caret].first;
            if (current_char == NULL)
                continue;   // 공백은 체크 안함. 

            //위 방향
            if (line > 0)
            {
                auto& t_temp_line = board_arr[line - 1];

                //왼쪽 위
                if (caret > 0)
                {
                    if (t_temp_line[caret - 1].first == current_char
                        && t_temp_line[caret].first == current_char
                        && temp_line[caret - 1].first == current_char)
                    {
                        t_temp_line[caret - 1].second++;
                        t_temp_line[caret].second++;
                        temp_line[caret - 1].second++;
                    }
                }

                //오른쪽 위
                if (caret < n - 1)
                {
                    if (t_temp_line[caret + 1].first == current_char
                        && t_temp_line[caret].first == current_char
                        && temp_line[caret + 1].first == current_char)
                    {
                        t_temp_line[caret + 1].second++;
                        t_temp_line[caret].second++;
                        temp_line[caret + 1].second++;
                    }
                }
            }

            //아랫 방향 
            if (line < m - 1)
            {
                auto& b_temp_line = board_arr[line + 1];

                //왼쪽 아래
                if (caret > 0)
                {
                    if (b_temp_line[caret - 1].first == current_char
                        && b_temp_line[caret].first == current_char
                        && temp_line[caret - 1].first == current_char)
                    {
                        b_temp_line[caret - 1].second++;
                        b_temp_line[caret].second++;
                        temp_line[caret - 1].second++;
                    }
                }

                //오른쪽 아래
                if (caret < n - 1)
                {
                    if (b_temp_line[caret + 1].first == current_char
                        && b_temp_line[caret].first == current_char
                        && temp_line[caret + 1].first == current_char)
                    {
                        b_temp_line[caret + 1].second++;
                        b_temp_line[caret].second++;
                        temp_line[caret + 1].second++;
                    }
                }
            }
        }
    }

    for (int line = 0; line < m; line++)
    {
        auto& temp_line = board_arr[line];
        for (int caret = 0; caret < n; caret++)
        {
            auto& info = temp_line[caret];
            if (info.second >= 3)
            {
                info = make_pair(NULL, 0);
                delete_count++;
            }
        }
    }

    return delete_count;
}

void SwapTile(pair<char, int>* a, pair<char, int>* b)
{
    pair<char, int> temp = *a;
    *a = *b;
    *b = temp;

    return;
}


int solution(int m, int n, vector<string> board) {
    int answer = 0;

    unordered_map<int, unordered_map<int, pair<char, int>>> board_arr;
    
    //세팅
    for (int line = 0; line < m; line++)
    {
        string& str = board[line];
        auto& temp_line = board_arr[line];
        for (int caret = 0; caret < n ; caret++)
        {
            temp_line[caret] = make_pair(str.at(caret), 0);
        }
    }

    do
    {
        auto delete_count = Delete2X2Tiles(m, n, board_arr);
        if (delete_count == 0)
            break;

        while (true)
        {
            for (int line = m - 1; line != 0; line--)
            {
                if (line < 1)
                    continue;

                auto& temp_line = board_arr[line];
                for (int caret = 0; caret < n; caret++)
                {
                    if (temp_line[caret].first == NULL)
                    {
                        auto& top_tile = board_arr[line - 1][caret];
                        if (top_tile.first == NULL)
                            continue;

                        SwapTile(&top_tile, &temp_line[caret]);
                    }
                }
            }

            bool bArranged = true;
            unordered_map<int, int> null_caret;
            for (int line = 0; line != m; line++)
            {
                auto& temp_line = board_arr[line];
                for (int caret = 0; caret < n; caret++)
                {
                    if (temp_line[caret].first == NULL)
                    {
                        auto itr = null_caret.find(caret);
                        if (itr == null_caret.end())
                        {
                            null_caret[caret] = line;
                        }
                        else
                        {
                            if (abs(itr->second - line) > 1)
                            {
                                bArranged = false;
                                break;
                            }
                            else
                            {
                                itr->second = line;
                            }
                        }
                    }
                }

                if (bArranged == false)
                    break;
            }

            if (bArranged == true)
                break;
        }


        answer += delete_count;

    } while (true);

    return answer;
}
