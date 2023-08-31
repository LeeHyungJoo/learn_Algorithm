#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    answer.resize(2, 0);

    int max_x = (board[0] - 1) * 0.5f;
    int max_y = (board[1] - 1) * 0.5f;


    for (auto& str : keyinput)
    {
        switch (str[0])
		{
		case 'l':
            answer[0]--;
			break;
		case 'r':
            answer[0]++;
			break;
        case 'u':
            answer[1]++;
            break;
        case 'd':
            answer[1]--;
            break;
        }

        //clamp
        if (answer[0] < 0)
        {
            if(answer[0] < (-1 * max_x))
                answer[0] = (-1 * max_x);
        }
        else if(answer[0] > 0)
        {
            if (answer[0] > max_x)
                answer[0] = max_x;
        }
        
        if (answer[1] < 0)
        {
            if (answer[1] < (-1 * max_y))
                answer[1] = (-1 * max_y);
        }
        else if (answer[1] > 0)
        {
            if (answer[1] > max_y)
                answer[1] = max_y;
        }
    }

    return answer;
}