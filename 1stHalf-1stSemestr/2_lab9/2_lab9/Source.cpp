#include <iostream>

using namespace std;

bool isNumber(char Symbol)
{
	return (Symbol >= '0' && Symbol <= '9') ? (true) : (false);
}

int main()
{
	bool check = 0;
	int num = 0, n = 0, j=0;
	char ourstring[20], ourstring2[20];
	char digits[10] = { 0,1,2,3,4,5,6,7,8,9 };
	cin >> ourstring;
	while ((ourstring[j]) != '\0')
	{
		n++;
		j++;
	}
	for (int i = 0; i < n; i++)
	{
		ourstring2[i] = ourstring[i];
		check = isNumber(ourstring[i]);
		if ( !check )
		{
			ourstring2[i] = digits[num] + 48;
			num++;
		}
		if (digits[i] == 9)
		{
			num = 0;
		}
	}
	cout << ourstring << endl;
	for (int i = 0; i < n; i++)
	{
		cout << ourstring2[i];
	}
	cout << endl;
	system("pause");

}