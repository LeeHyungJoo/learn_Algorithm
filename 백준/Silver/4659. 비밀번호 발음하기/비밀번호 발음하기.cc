#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <chrono>
#include <math.h>
#include <bitset>
#include <set>
#include <regex>
#include <iostream>

using namespace std;

bool IsVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool IsAcceptablePassword(const string& password)
{
	int prev_idx = -1;
	int conso = 0, vowel = 0;

	bool vowel_check = false;
	bool triple_check = false;
	bool double_duplicated_check = false;

	for (int idx = 0; idx < password.size();idx++)
	{
		char last_char = prev_idx < 0 ? ' ' : password[prev_idx];

		if (!vowel_check && IsVowel(password[idx]))
			vowel_check = true;

		if (last_char == ' ')
		{
			IsVowel(password[idx]) ? ++vowel : ++conso;
		}
		else
		{
			if (IsVowel(last_char))
			{
				if (IsVowel(password[idx]))
				{
					++vowel;
				}
				else
				{
					vowel = 0;
					++conso;
				}
			}
			else
			{
				if (IsVowel(password[idx]))
				{
					conso = 0;
					++vowel;
				}
				else
				{
					++conso;
				}
			}

			if (last_char != 'e' && last_char != 'o')
			{
				if (last_char == password[idx])
				{
					double_duplicated_check = true;
				}
			}
		}

		if (conso == 3 || vowel == 3)
		{
			triple_check = true;
		}

		if (triple_check || double_duplicated_check)
			break;
		prev_idx = idx;
	}
	
	return !(triple_check || double_duplicated_check) && vowel_check;
}


int  main()
{
	while (true)
	{
		string password;
		cin >> password;
		if (password == "end")
			break;

		if (IsAcceptablePassword(password))
		{
			cout << "<" << password << "> is acceptable." << endl;
		}
		else
		{
			cout << "<" << password << "> is not acceptable." <<endl;
		}
	}

	return 0;
}