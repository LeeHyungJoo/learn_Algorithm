#include <iostream>
using namespace std;
int count;
int target;

int  main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	cin >> count;
   
	for (int i = 0; i < count; ++i)
	{
		cin >> target;

		int answer = 0;
		for (int num = 5; num <= target; num *= 5 )
        {
			answer += target / num;
        }

		cout << answer << "\n";
	}

	return 0;
}