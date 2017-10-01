#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

template <class T>
class OurClass 
{
private:
	int size;
	T* ptr;
public:
	OurClass(int s = 5)
	{
		size = s;
		ptr = new T[size];
		for (int i = 0; i < size; i++)
			ptr[i] = 0;
	}

	void AnitClass()
	{
		T symbol;
		cout << "Zapolnite massiv " << size << " simvolami :" << endl;
		for (int i = 0; i < size; i++)
		{
			cin >> symbol;
			ptr[i] = symbol;
		}
	}

	void GetClass()
	{
		for (int i = 0; i < size; i++)
		{
			cout << setw(4) << ptr[i] << "   ";
		}
		cout << endl;
	}

	T* ShowData()
	{
		return ptr;
	}

	OurClass<T>(const OurClass <T> & object):size(object.size)
	{
		ptr = new T[size];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = object.ptr[i];
		}
	}

	const OurClass<T> & operator=(const OurClass<T> & object)
	{
		cout << "Proizvodim prisvaivanie :" << endl;
		if (size != object.size)
		{
			delete[] ptr;
			size = object.size;
			ptr = new T[size];
		}
		for (int i = 0; i < size; i++)
		{
			ptr[i] = object.ptr[i];
		}
		cout << endl;
		return*this;
	}

	void operator+ (const OurClass<T> & object)
	{
		T res = 0;
		cout << "Symma :" << endl;
		for (int i = 0; i < size; i++)
		{
			res = ptr[i] + object.ptr[i];
			ptr[i] = res;
			res = 0;
		}
		cout << endl;
	}

	void Proc()
	{
		cout << "Koren' i ydvoenie :" << endl;
		double res = 0;
		for (int i = 0; i < size; i++)
		{
			res = sqrt(ptr[i]);
			ptr[i] = 2*res;
		}
		cout << endl;
	}

	~OurClass()
	{
		delete[] ptr;
		cout << "DATA CLEANED" << endl;
	}

	
};

int main()
{
	OurClass<int> obj;
	obj.AnitClass();
	obj.GetClass();
	obj.Proc();
	obj.GetClass();

	OurClass<int> obj2;
	obj2.AnitClass();
	obj2.GetClass();
	obj2 + obj;
	obj2.GetClass();
	obj2 = obj;
	obj2.GetClass();

	OurClass<int> obj3(obj);
	cout << "Kopiryem 1 obj v 3 :" << endl;
	obj3.GetClass();
	
	cout <<"Pokazivaem adres 1 obj\n" << obj.ShowData() << endl;

	OurClass<double> obj4;
	obj4.AnitClass();
	obj4.GetClass();

	system("pause");
}