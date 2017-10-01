#include <iostream>
#include <conio.h>
using namespace std;
double function1(int n = 16);
double function2();
int main()
{
	setlocale(LC_ALL, "");
	char ch;
	do {
		cout << "Выберите как решать интеграл:\n";
		cout << "1. с умалчиваемым значением параметра\n";
		cout << "2. с другим значением этого параметра\n";
		cout << "3. по формуле Ньютона - Лейбница\n";
		int choose;
		cin >> choose;
		double answer;
		switch (choose)
		{
		case 1: answer = function1(); break;
		case 2: int n; cout << "Выберите значение параметра: "; cin >> n; answer = function1(n); break;
		case 3: answer = function2(); break;
		}
		cout << "Ответ: " << answer << endl;
		cout << "Хотите продолжить? (y/n)";
		cin >> ch;
	} while (ch == 'y');
	_getche();
	return 0;
}
double function1(int n)
{
	double h = 2.0 / n;
	double s1 = 0;
	double s2 = 0;
	double x = 1 + h;
	int k = 0;
	while (x <= 3 - h) {
		if (k % 2 == 0)
			s1 += pow(x, x)*(1 + log(x));
		else s2 += pow(x, x)*(1 + log(x));
		k++;
		x += h;
	}
	return h / 3 * (1 + 4 * s1 + 2 * s2 + 27 * (1 + log(3)));
}
double function2(void)
{
	double q = pow(3, 3);
	double w = pow(1, 1);
	return q - w;
}
