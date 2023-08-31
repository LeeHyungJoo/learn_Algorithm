#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, char> morse = {
{".-",'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'}, {"." , 'e'}, {"..-." , 'f'},
{"--." , 'g'}, {"...." , 'h'}, {".." , 'i'}, {".---" , 'j'}, {"-.-" , 'k'}, {".-.." , 'l'},
{"--" , 'm'}, {"-." , 'n'}, {"---" , 'o'}, {".--." , 'p'}, {"--.-" , 'q'}, {".-." , 'r'},
{"..." , 's'}, {"-" , 't'}, {"..-" , 'u'}, {"...-",'v'}, {".--" , 'w'}, {"-..-" , 'x'},
{"-.--" , 'y'}, {"--.." , 'z'} };
string solution(string letter) {
    string answer = "";

    string unit;
    for (int i = 0; i < letter.size(); i++)
    {
        if (i == letter.size() - 1)
        {
            unit.push_back(letter[i]);
            answer.push_back(morse[unit]);
            unit.clear();
        }
        else if (letter[i] == ' ')
        {
            answer.push_back(morse[unit]);
            unit.clear();
        }
        else
        {
            unit.push_back(letter[i]);
        }
    }

    return answer;
}