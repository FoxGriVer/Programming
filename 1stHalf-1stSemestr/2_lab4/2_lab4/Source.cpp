#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	char mas[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> mas[i];
	}
	for (int i = 0; i < 8; i++)
	{
		if (mas[i] & 0x01) { mas[i] &= ~0x01; }
		else { mas[i] |= 0x03; }
	}
	for (int i = 0; i < 8; i++)
	{
		cout << mas[i];
	}
	cout << endl;
	system("pause");
}
