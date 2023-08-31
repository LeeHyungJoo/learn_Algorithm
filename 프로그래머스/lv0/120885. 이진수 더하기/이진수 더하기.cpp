#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";

    char round_off = '0';
    int max_size = (bin1.size() > bin2.size() ? bin1.size() : bin2.size());
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    for (int i = 0; i < max_size; i++)
    {
        char b1 = '0';
        char b2 = '0';

        if (i < bin1.size())
            b1 = bin1[i];

        if (i < bin2.size())
            b2 = bin2[i];

        int b_count = 0;
        for (auto b : { b1, b2, round_off })
            if (b == '1')
                b_count++;

        switch (b_count)
        {
        case 0 :
            round_off = '0';
            answer.push_back('0');
            break;
        case 1:
            round_off = '0';
            answer.push_back('1');
            break;
        case 2:
			answer.push_back('0');
			if (i == max_size - 1) answer.push_back('1');
            else round_off = '1';
            break;
        case 3:
            answer.push_back('1');
            if (i == max_size - 1) answer.push_back('1');
            else round_off = '1';
            break;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}