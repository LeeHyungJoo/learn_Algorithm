#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {
    // step1
    for(auto &c : new_id) 
    {
        if(c >= 'A' && c<='Z') 
            c = 'a' + c - 'A';
    }

    // step2
    regex re("[^A-Za-z0-9._-]");
    new_id = regex_replace(new_id, re, "");

    // step3
    regex re1("\\.+");
    new_id = regex_replace(new_id, re1, ".");

    // step4
    if(new_id[0] == '.') 
        new_id.erase(new_id.begin());
    if(new_id.back() == '.') 
        new_id.pop_back();

    // step5
    if(new_id.empty())  
        new_id = "a";

    // step6
    if(new_id.size() > 15)  
        new_id = new_id.substr(0, 15);
    if(new_id.back() == '.')    
        new_id.pop_back();

    // step7
    while(new_id.size() <= 2)
        new_id.push_back(new_id.back());

    return new_id;
}