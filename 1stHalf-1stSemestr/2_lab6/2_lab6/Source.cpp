#include <iostream>

using namespace std;

int main()
{
	int sum;
	int mas[10] = { 0 }, masres[10] = { 0 };
	bool check = 0, prevcheck = 0, fincheck = 0;
	cout << "Zapolnite massiv : " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> mas[i];
	}

	for (int i = 0; i < 9; i++)
	{
		prevcheck = mas[i] % 2;
		check = mas[i+1] % 2;
		if ((prevcheck == true) && (check == false))
		{
			fincheck = 1;
		}
	}

	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		if (!fincheck)
		{
			if (mas[i] < 0)
			{
				masres[num] = mas[i];
				num++;
			}
		}
		else
		{
			if (mas[i] >= 0)
			{
				masres[num] = mas[i];
				num++;
			}
		}
	} 
	cout << "Result : " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << masres[i] << " ";
	}
	cout << endl;

	system("pause");
}