#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {

	stable_sort(files.begin(), files.end(), [&files](const string& lhs, const string& rhs) -> bool
		{
			string lhs_head, rhs_head;
			int lhs_number, rhs_number;

			string number_str;
			bool check = false;
			for (int i = 0; i < lhs.size(); i++)
			{
				if (!isdigit(lhs[i]))
				{
					if (check) break;
					lhs_head.push_back(tolower(lhs[i]));
				}
				else
				{
					check = true;
					number_str.push_back(lhs[i]);
				}
			}
			lhs_number = atoi(number_str.c_str());

			number_str.clear();
			check = false;

			for (int i = 0; i < rhs.size(); i++)
			{
				if (!isdigit(rhs[i]))
				{
					if (check) break;
					rhs_head.push_back(tolower(rhs[i]));
				}
				else
				{
					check = true;
					number_str.push_back(rhs[i]);
				}
			}

			rhs_number = atoi(number_str.c_str());

			if (lhs_head < rhs_head)
			{
				return true;
			}
			else if (lhs_head == rhs_head)
			{
				if (lhs_number < rhs_number)
				{
					return true;
				}
			}

			return false;
		});

	return files;
}
