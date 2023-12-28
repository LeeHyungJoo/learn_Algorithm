#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> cores) 
{
	if (n <= cores.size())
	{
		return n;
	}

	int s_time = -1, e_time = 2e5;
	int m_time;

	while (s_time  + 1 < e_time)
	{
		m_time = (s_time + e_time) >> 1;

		int cnt = cores.size();
		for (int idx = 0; idx < cores.size(); ++idx)
		{
			cnt += m_time / cores[idx];
		}

		if (cnt < n)
		{
			s_time = m_time;
		}
		else
		{
			e_time = m_time;
		}
	}

	int cnt = cores.size();
	for (int i = 0;i < cores.size();i++)
	{
		cnt += s_time / cores[i];
	}

	int answer = 0;
	for (int i = 0;i < cores.size();i++) 
	{
		if ((s_time + 1) % cores[i] == 0)
		{
			cnt++;
		}

		if (cnt == n)
		{
			answer = i + 1;
			break;
		}
	}

	return answer;
}
