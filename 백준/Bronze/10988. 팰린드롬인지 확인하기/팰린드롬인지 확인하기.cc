#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	int ret = 1;
	for (int idx = 0; idx < str.size() / 2; idx++)
	{
		if (str[idx] != str[str.size() - idx - 1])
		{
			ret = 0;
			break;
		}
	}

	cout << ret;

	return 0;
}