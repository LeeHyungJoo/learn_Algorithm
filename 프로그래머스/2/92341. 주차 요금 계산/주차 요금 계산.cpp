#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

vector<string> split(string str, char delimeter = ' ')
{
	vector<string> ret;
	int start_idx = 0;
	for (int idx = start_idx; idx < str.size(); idx++)
	{
		if (idx == str.size() - 1)
		{
			auto split_str = str.substr(start_idx, str.size());
			if (!split_str.empty())
				ret.push_back(split_str);
		}

		if (str[idx] != delimeter)
			continue;

		auto split_str = str.substr(start_idx, idx - start_idx);
		if (!split_str.empty())
			ret.push_back(split_str);

		start_idx = idx + 1;
	}

	return ret;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
	map<int, pair<stack<int>, int>> recordChecks;

	for (auto& record : records)
	{
		auto info = split(record);
		auto& recordInfo = recordChecks[atoi(info[1].c_str())];

		auto timeStr = split(info[0], ':');
		auto time = atoi(timeStr[0].c_str()) * 60 + atoi(timeStr[1].c_str());

		if (recordInfo.first.empty())
		{
			recordInfo.first.push(time);
		}
		else 
		{
			auto inTime = recordInfo.first.top();
			recordInfo.first.pop();
			recordInfo.second += (time - inTime);
		}
	}

	for (auto& record : recordChecks)
	{
		if (!record.second.first.empty())
		{
			auto inTime = record.second.first.top();
			record.second.first.pop();
			record.second.second += 1439 - inTime;
		}

		int fee = fees[1];
		if (record.second.second > fees[0])
		{
			int perMin = (record.second.second - fees[0]) / fees[2];
			if ((record.second.second - fees[0]) % fees[2] > 0)
				perMin++;

			fee += (perMin * fees[3]);
		}

		answer.push_back(fee);
	}

    return answer;
}