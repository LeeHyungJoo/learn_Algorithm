#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	unordered_map<string, pair<int, set<string>>> report_count;
	set<string> duplicated_report;
	for (auto & dup : report)
	{
		duplicated_report.insert(dup);
	}

	for (auto& rep_unit : duplicated_report)
	{
		auto found = rep_unit.find(' ');
		if (found == string::npos)
			continue;

		auto itr = report_count.find(rep_unit.substr(found + 1));
		if (itr != report_count.end())
		{
			itr->second.first++;
			itr->second.second.insert(rep_unit.substr(0, found));
		}
		else
		{
			report_count[rep_unit.substr(found + 1)] = make_pair(1, set<string>({ rep_unit.substr(0,found) }));
		}
	}

	unordered_map<string, int> mail_count;
	for (auto& report_unit : report_count)
	{
		if (report_unit.second.first < k)
			continue;
		
		for (auto& reporter_unit : report_unit.second.second)
			mail_count[reporter_unit]++;
	}

	for (auto id : id_list)
	{
		auto itr = mail_count.find(id);
		if (itr == mail_count.end())
			answer.push_back(0);
		else
		{
			answer.push_back(itr->second);
		}
	}

	return answer;
}