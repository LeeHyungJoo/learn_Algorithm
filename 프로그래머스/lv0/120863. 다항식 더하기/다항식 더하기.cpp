#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
     string answer = "";

    int offset = 0;
    int x_num = 0, num = 0;
    while (true)
    {
        auto idx = polynomial.find(' + ', offset);
        if (idx == string::npos)
        {
            //맨 끝 부분
            string str = polynomial.substr(offset, idx - offset);
            auto x_idx = str.find('x');
            if (x_idx == string::npos)
            {
                num += atoi(str.c_str());
            }
            else
            {
                string x_num_str = str.substr(0, x_idx);
                if (!x_num_str.empty())
                    x_num += atoi(x_num_str.c_str());
                else
                    x_num += 1;
            }

            break;
        }

        string str = polynomial.substr(offset, idx - offset);
        auto x_idx = str.find('x');
        if (x_idx == string::npos)
        {
            num += atoi(str.c_str());
        }
        else
        {
            string x_num_str = str.substr(0, x_idx);
            if (!x_num_str.empty())
                x_num += atoi(x_num_str.c_str());
            else
                x_num += 1;
        }

        offset = idx + 1;
    }

    if (x_num != 0)
    {
        if(x_num != 1)
            answer += to_string(x_num);
        
        answer += "x";
        if (num != 0)
        {
            answer += " + ";
            answer += to_string(num);
        }
    }
    else
    {
        if (num != 0)
        {
            answer += to_string(num);
        }
    }

    return answer;
}