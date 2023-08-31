#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;
	for (int x = 0; x < b; x++)
	{
		for (int y = 0; y < a; y++)
			cout << '*';
		cout << endl;
	}
    return 0;
}