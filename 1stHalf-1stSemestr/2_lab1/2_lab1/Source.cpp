#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x, y, res,avarage;
	cout << "Vvedite dannie " << endl;
	cin >> x >> y;
	avarage = log10( 1 - 2 * x + 3 * x*x - 4 * pow(x, 3) );
	res = fabs(avarage) + (sqrt(fabs(x))) / y;
	cout << "Rezult : " << res << endl;
	system("pause");
	
}