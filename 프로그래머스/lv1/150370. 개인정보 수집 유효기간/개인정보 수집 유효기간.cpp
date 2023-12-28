#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int calculDays(const string& date)
{
	size_t y_i = date.find('.');
	size_t m_i = date.find('.', y_i + 1);

	return ((atoi(date.substr(0, y_i).c_str()) - 2000) * 12 * 28) + ((atoi(date.substr(y_i + 1, m_i).c_str()) * 28) + atoi(date.substr(m_i + 1, 2).c_str()));
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {

	const int t_days = calculDays(today);

	unordered_map<char, int> d_maps;
	for (const string& term : terms)
	{
		auto s = term.find(' ');
		d_maps[term.substr(0, s)[0]] = atoi(term.substr(s + 1, term.size()).c_str()) * 28;
	}

	vector<int> answer;
	for (int i = 0; i < privacies.size(); i++)
	{
		auto s = privacies[i].find(' ');
		if (calculDays(privacies[i].substr(0, s)) + d_maps[privacies[i].substr(s + 1, privacies[i].size())[0]] - 1 < t_days)
			answer.push_back(i + 1);
	}

	return answer;
}