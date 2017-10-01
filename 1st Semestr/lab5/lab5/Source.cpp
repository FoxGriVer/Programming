#include <iostream>

using namespace std;

class Pair
{
protected :
	int first, second;

public:
	Pair(int fst = 0, int sec = 0)
	{
		first = fst;
		second = sec;
	}

	void Compar(int fst, int sec)
	{
		if (fst > sec)
		{
			cout << fst << " > " << sec << endl;
		}
		else if (fst == sec)
		{
			cout << fst << " = " << sec << endl;
		}
		else
		{
			cout << sec << " > " << fst << endl;
		}
	}

	void Mult(int fst, int sec)
	{
		int result;
		result = fst * sec;
		cout << fst << " * " << sec << " = " << result << endl;
	}

	void VichPair(int fst1, int sec1, int fst2, int sec2)		 
	{
		int res_fst, res_sec;
		res_fst = fst1 - sec1;
		res_sec = fst2 - sec2;
		cout << "(" << fst1 << ", " << sec1 << ") - (" << fst2 
			<< ", " << sec2 << ") = (" << res_fst << ", " << res_sec << ")" << endl;
	}
};

class Rational : public Pair
{
protected:
	int fstint, secint;

public :
	Rational(int a, int b) : Pair(a, b)
	{
		fstint = a;
		secint = b;
	}

	void SummRat(int fst1, int sec1, int fst2, int sec2)
	{
		int res_fst, res_sec;
		res_fst = (fst1 * sec2) + ( sec1 * fst2);
		res_sec = sec1 * sec2;
		cout << "(" << fst1 << ", " << sec1 << ") + (" << fst2
			<< ", " << sec2 << ") = (" << res_fst << ", " << res_sec << ")" << endl;
	}

	void DivRat(int fst1, int sec1, int fst2, int sec2)
	{
		int res_fst, res_sec;
		res_fst = fst1 * sec2;
		res_sec = sec1 * fst2;
		cout << "(" << fst1 << ", " << sec1 << ") / (" << fst2
			<< ", " << sec2 << ") = (" << res_fst << ", " << res_sec << ")" << endl;
	}

};

int main()
{
	int number1, number2, number3, number4;
	cout << " Vvedite chisla " << endl;
	cin >> number1 >> number2 >> number3 >> number4;
	cout << endl;

	Pair OurObjComp(number1, number2);
	Rational OurObjRat(number1, number2);

	cout << " Bazovii class : " << endl;
	OurObjComp.Compar(number1, number2);
	OurObjComp.Mult(number1, number2);
	OurObjComp.VichPair(number1, number2, number3, number4);
	cout << endl;

	cout << " Proizvodnii class : " << endl;
	OurObjRat.Compar(number1, number2);
	OurObjRat.Mult(number1, number2);
	OurObjRat.VichPair(number1, number2, number3, number4);
	OurObjRat.SummRat(number1, number2, number3, number4);
	OurObjRat.DivRat(number1, number2, number3, number4);
	cout << endl;

	system("pause");
}