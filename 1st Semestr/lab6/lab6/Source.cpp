#include <iostream>

using namespace std;

class LongLong
{
private:

	long star;
	unsigned long mlad;

public:
	LongLong(long s = 0, unsigned long m = 0) : star(s), mlad(m)
	{}

	void Display()
	{
		cout <<star << "," << mlad << endl;
	}

	LongLong operator+ (LongLong& obj)
	{
		LongLong res;
		res.star = star + obj.star;
		res.mlad = mlad + obj.mlad;

		return res;
	}
	
	LongLong operator- (LongLong& obj)
	{
		LongLong res;
		if (obj.star > star)
		{
			cout << "Nekorektnie znachenia" << endl;
			return res;
		}
		res.star = star - obj.star;
		if (obj.mlad > mlad)
		{
			res.mlad = mlad - obj.mlad + 10000;
			res.star--;
		}
		else
		{
			res.mlad = mlad - obj.mlad;
		}

		return res;
	} 

	bool operator> (LongLong& obj)
	{
		if (star > obj.star)
		{
			return true;
		}
		else return false;
	}

	bool operator== (LongLong& obj)
	{
		if (star == obj.star && obj.mlad)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(LongLong& obj)
	{
		return obj.star > this->star;
	}
	
};

//bool operator> (LongLong& obj1, LongLong& obj2)
//{
//	if(obj1.star)
//}

int main()
{
	int n1, n2, n3, n4;					
	bool check = false;

	cout << " Vvodim dannie " << endl << endl;
	do
	{
		cin >> n1 >> n2 >> n3 >> n4;
		if (n1 > 10000 || n2 > 10000 || n3 > 10000 || n4 > 10000)
		{
			cout << "Nevernii vvod, povtorite" << endl << endl;
			check = true;
		}
		else
		{
			check = false;
		}
	} while (check);
	cout << endl;

	LongLong OurObj1(n1, n2);
	LongLong OurObj2(n3, n4);
	LongLong Result;
	
	cout << "Symma : " << endl;
	Result = OurObj1 + OurObj2;
	Result.Display();
	cout << endl;

	cout << "Raznost' : " << endl;
	Result = OurObj1 - OurObj2;
	Result.Display();
	cout << endl;

	cout << "Ravenstvo : " << endl;
	check = false;
	check = OurObj1 == OurObj2;
	cout << check;
	cout << endl << endl; 

	cout << "obj1 > obj2 : " << endl;
	check = false;
	check = OurObj1 > OurObj2;
	cout << check;
	cout << endl << endl;

	cout << "obj1 < obj2 : " << endl;
	check = false;
	check = OurObj1 < OurObj2;
	cout << check;
	cout << endl << endl;

	system("pause");
}