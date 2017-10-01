#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int ourmas[5][4] = { {0},{0},{0},{0},{0} };
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> ourmas[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		if (((i + 1) == 1) || ((i + 1) == 3) || ((i + 1) == 5))
		{
			for (int j = 0; j < 4; j++)
			{
				if (ourmas[i][j] < 0)
				{
					sum += ourmas[i][j];
				}
			}
		}
	}

	vector<int> ourvect(5);
	for (int i = 0; i < 5; i++)
	{
		ourvect[i] = ourmas[i][0];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout <<setw(4) << ourmas[i][j];
		}
		cout << endl;
	}
	cout << endl;

	ourmas[0][0] = sum;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << setw(4) << ourmas[i][j];
		}
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < ourvect.size(); i++)
	{
		cout << ourvect[i] << " ";
	}
	cout << endl;

	system("pause");
}