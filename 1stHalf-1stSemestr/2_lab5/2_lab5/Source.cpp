#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	double sum;
	double mas[30] = { 0 };
	mas[0] = 1.01;
	mas[1] = 0.75;
	sum = mas[0] + mas[1];
	for (int i = 2; i < 30; i++)
	{
		sum += 0.25*(i + 1) + 2 * sin(mas[i]) - 0.35*cos(mas[i - 1]);
	}
	cout << "Result : " << sum << endl;

	system("pause");
}