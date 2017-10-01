#include <iostream>
#include <cmath>

using namespace std;

class OurClass
{
	private:
		double first, second, proizv;

	public:
		OurClass(double number = 3.1456)
		{
			second = modf(number, &first);
			first = first;
		}

		void Display()
		{
			double fst, sec;
			fst = first;
			sec = second;
			cout << " Celaia chast' : " << first << endl;
			cout << " Drobnaia chast' : " << second << endl;
		}
		double Multiply(double pervii = 0, double vtoroii = 0)
		{
			proizv = pervii * vtoroii;
			return proizv;
		}

		~OurClass()
		{
			cout << "                 !!! RABOTAET DESTRYKTOR !!!                     " << endl;

		}


};

int main()
{
	double ournumber, fstdbl, secdbl, result;
	int check;
	cout << "Vvedite chislo" << endl;
	cin >> ournumber;
	OurClass ourclass(ournumber);
	ourclass.Display();
	cout << "Hotite proizvesti ymnojenie ? " << endl;
	cin >> check;
	if (check)
	{
		cout << "vvedite 2 chisla" << endl;
		cin >> fstdbl >> secdbl;
		result = ourclass.Multiply(fstdbl, secdbl);
		cout << " Rezultat proizvedenia : " << result << endl;
	}
	
	system("pause");
}