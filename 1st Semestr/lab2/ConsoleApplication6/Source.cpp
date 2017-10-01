#include <iostream>
#include <string>  
#include <iomanip>

using namespace std;

int Date(int D, int M, int Y)
{
	int a, y, m, R;
	a = (14 - M) / 12;
	y = Y - a;
	m = M + 12 * a - 2;
	R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
	return R % 7;
}

int main()
{
	int thu, res = 0, ourYear, month = 1, daysAll, dayInMonth = 0;
	int Thues[35][15] = { {0}, {0} };
	cout << "Vvedite god ";
	cin >> ourYear;
	if (((ourYear % 4 != 0) || (ourYear % 100 == 0)) && (ourYear % 400 != 0))
	{
		cout << "God NE vesokosnii" << endl;
		daysAll = 365;
	}
	else 
	{
		cout << "God vesokosnii" << endl;
		daysAll = 366;
	}
	for (int i = 1; i <= daysAll; i++)
	{
		switch (month)
		{
		case 3 : case  5: case 6: case 7: case  8: case 10: case 12: 
		{
			if (dayInMonth == 31)
			{
				dayInMonth = 1;
				month++;
				break;
			}
			else
			{
				dayInMonth++;
			}
			break;
		}
		case  1: case 4: case  9: case 11:
		{
			if (dayInMonth == 30)
			{
				dayInMonth = 1;
				month++;
				break;
			}
			else
			{
				dayInMonth++;
			}
			break;
		}
		case 2:
		{
			if (((dayInMonth == 28) && ((ourYear % 4 != 0) || (ourYear %
				100 == 0)) && (ourYear % 400 != 0)) || (dayInMonth == 29))
			{
				dayInMonth = 1;
				month++;
				break;
			}
			else
			{
				dayInMonth++;
			}
			break;
		}

		default:   cout << "Chto-to ne tak";
			break;
		}
		thu = Date(dayInMonth, month, ourYear);
		if (thu == 4)
		{
			Thues[dayInMonth][month] = 1;
		}
		else
		{
			Thues[dayInMonth][month] = 0;
		}

	}
	for (int i = 0; i <= 12; i++)
	{
		cout << endl;
		for (int j = 0; j < 35; j++)
		{
			if (Thues[j][i] == 1)
			{
				cout <<setw(4) <<  j  << " " << i << " Thuesday " << endl;
			}
		}
	}
	///*for (int i = 3; i > 0; i--)
	//{*/
	//	cin >> D >> C >> M >> C >> Y;
	//	thu = Date(D, M, Y);
	//	/*if (thu == 4) res++;
	//	else cout << "NoN" << endl;
	//}*/
	//cout << thu;

	system("pause");
	return 0;
}