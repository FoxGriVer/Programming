#include <iostream>

using namespace std;

int main()
{
	double x, y, res;
	cout << "Vvedite dannie " << endl;
	cin >> x >> y;
	if (x < -2)
	{
		res = (3 * x*x + 2 * y) / (x*x + y*y);
	}
	if ((x >= -2) && (x <= 2))
	{
		res = fabs(x - 3 * y);
	}
	if (x > 2)
	{
		res = log10(fabs((x - y) / (2 + 3 * y)));
	}
	cout << "Result : " << res << endl;
	system("pause");
}