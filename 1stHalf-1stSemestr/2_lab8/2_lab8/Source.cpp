#include <iostream>
using namespace std;
int main()
{
	int i, j, N, M;
	int *a, *b, *c;

	cout << "N = "; 
	cin >> N;
	cout << "M = "; 
	cin >> M;

	a = new int[N*M];
	b = new int[N*M];
	c = new int[N*M];

	cout << "Vvedite matricy A" << endl;
	for (i = 0; i<N; i++)
		for (j = 0; j<M; j++)
		{
			cin >> *(a + i*M + j);
		}

	cout << "Vvedite matricy B" << endl;
	for (i = 0; i<N; i++)
		for (j = 0; j<M; j++)
		{
			cin >> *(b + i*M + j);
		}
	
	for (i = 0; i<N; i++)
		for (j = 0; j<M; j++)
			*(c + i*M + j) = *(a + i*M + j) + *(b + i*M + j);

	cout << "Matrica C :" << endl;
	for (i = 0; i<N; cout << endl, i++)
		for (j = 0; j<M; j++)
			cout << *(c + i*M + j) << "\t";

	delete[]a;
	delete[]b;
	delete[]c;

	system("pause");
}