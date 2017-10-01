#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;

struct Student
{
	char name[30];
	int subFiz, subMath, subLit, initnum;
	float midbal;

};

bool isNumber(char Symbol)
{
	return (Symbol >= '0' && Symbol <= '9') ? (true) : (false);
}

void ShowVed()
{
	char line[30];
	ifstream ourfile("our.txt");
	if (ourfile.is_open())
	{
		while (ourfile.good())
		{
			ourfile.getline(line, sizeof(line));
			cout << line << endl;
		}
		ourfile.close();
	}
}

void bubleSort(float *arrayPtr)
{
	float temp = 0; 
	int ourarray = 5;
	bool exit = false;

	while (!exit)
	{
		exit = true;
		for ( int i = 0; i < (ourarray - 1); i++)
			if (arrayPtr[i] < arrayPtr[i + 1])
			{
				temp =	arrayPtr[i];	
				arrayPtr[i] = arrayPtr[i + 1];
				arrayPtr[i + 1] = temp;
				exit = false;
			}
	}
}


int main()
{
	int check, a, b, c;
	char  str[30];
	Student stud[5];
	cout << "hotite zapolnit' vedomost' ? " << endl;
	cin >> check;
	if (check)
	{
		cout << "Est' piat' studentov ? " << endl << endl;
		for (int i = 1; i <= 5; i++)
		{
			cout << "Vvedite imia dlia " << i << endl;
			cin >> str;
			cout << "Vvedite ocenki " << endl;
			cin >> a >> b >> c;
			stud[i].subFiz = a;
			stud[i].subMath = b;
			stud[i].subLit = c;
			stud[i].initnum = i;
			strcpy_s(stud[i].name, str);
		}
		ofstream ourfile("our.txt");
		for (int i = 1; i <= 5; i++)
		{
			ourfile << setw(7) << stud[i].name << setw(3) << stud[i].subFiz
				<< setw(3) << stud[i].subMath << setw(3) << stud[i].subLit << endl;
		}
		ourfile.close();
	}
	cout << "Vivodim imeyshyiasa vedomost' " << endl;
	ShowVed();
	cout << endl;

	//rashet srednego balla 
	ifstream ourfile("our.txt");
	int masint[5][3] = { {0}, {0} }, i, m, chislo;
	char masmax[250], buff[2];
	i = 0;
	m = 0;
	for (int h = 0; h < 250; h++)
	{
		ourfile >> masmax[h];
		if (isNumber(masmax[h]))
		{
			buff[0] = masmax[h];
			buff[1] = '\0';
			chislo = atoi(buff);
			masint[m][i] = chislo;
			i++;
			if (i == 3)
			{
				i = 0;
				m++;
			}
		}
	}
	ourfile.close();
	float f_srball, srball = 0, srbalstud = 0, maswithsr[5];

	//raschet srednego balla y kajdogo studenta
	for (int j = 0; j < m; j++)
	{
		cout << endl;
		srbalstud = 0;
		for (int k = 0; k < 3; k++)
		{
			srball += masint[j][k];
			srbalstud += masint[j][k];
			stud[j].midbal = srbalstud / 3;
		}
		maswithsr[j] = stud[j].midbal;
	}
	f_srball = srball / 15;
	cout << "Srednii ball : " << round(f_srball * 100) / 100 << endl << endl;
	//vivodim bal s iminem do sortirovki
	if (check != 0)
	{
		for (int i = 0; i < m; i++)
		{
			cout << "Srednii ball y " << setw(7) << stud[i + 1].name << " : " << round(stud[i].midbal * 100) / 100 << endl;
		}
		cout << endl;
	}

	//sortiryem
	bubleSort(maswithsr);

	//vivodim otsortirovanii spisok
	if (check != 0)
	{
		double eps = 1e-2;
		for (int i = 0; i < 5; i++)
		{
			float lastcheck = 0;
			lastcheck = round(maswithsr[i] * 100) / 100;
			for (int i = 0; i < 5; i++)
			{
				if (fabs(lastcheck - stud[i].midbal) < eps)
				{
					cout << stud[i + 1].name << " " << stud[i].midbal << endl;
				}
			}
		}
	}

	if (check == 0)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << maswithsr[i] << endl;
		}
	}


	system("pause");
}