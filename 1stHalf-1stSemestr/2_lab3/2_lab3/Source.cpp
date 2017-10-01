#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double res = 0;

	for (double x = -1.5; x <= -0.5; x += 0.1)
	{
		if (x < -1)
		{
			res = 1 / pow((3 * sin(x) + 2 * cos(x)), 2);
		}
		if (x >= -1)
		{
			res = 3 / 26 - (3 * cos(x) - 2 * sin(x)) / 13 * (2 * cos(x) + 3 * sin(x));
		}
		cout.precision(4);
		cout << setw(5) << x << " | " << setw(5) << res << endl;
	}
	system("pause");
}