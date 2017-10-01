#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int i, j;
	const int N=5;
	char words[N][15] = { 0 }, cur[30];
	char word1[N][15] = { 0 }, word2[N][15] = { 0 }, word3[N][15] = { 0 }, word4[N][15] = { 0 }, word5[N][15] = { 0 };
	char mas[N][15] = { 0 };
	vector<string>vecStr2;
	vector<string>vecStr1;
	vector<string>vecStr5;
	vector<string>vecStr3;
	vector<string>vecStr4;

	//Vvod slov
	cout << "Vvedite 5 slov ne dlinneie 4 simvolov:\n";
	for (i = 0; i<N; i++)
		cin.getline(words[i], 30);
	//Pyzirek
	for (i = 0; i<N - 1; i++)
		for (j = i + 1; j<N; j++)
			if (strcmp(words[i], words[j])>0)
			{
				strcpy_s(cur, words[i]);
				strcpy_s(words[i], words[j]);
				strcpy_s(words[j], cur);
			}
	//cout << "Results:\n";

	//for (i = 0; i<N; i++)
	//	cout << words[i] << "\n";

	//Raspredeliaem v svoi vektor po kol-vy bookv
	int p = 0, k = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (words[i][j] == 0)
			{
				p = j + 1;
				/*cout << "v " << i + 1 << " slove " << p << " element probel" << endl;*/
					switch (p)
					{
						case 2: {
							vecStr1.push_back(words[i]);
							vecStr1.push_back(" ");
							break;
						}
						case 3: {
							vecStr5.push_back(words[i]);
							vecStr5.push_back(" ");
							break;
						}
						case 4: {
							vecStr3.push_back(words[i]);
							vecStr3.push_back(" ");
							break;
						}
						case 5: {
							vecStr4.push_back(words[i]);
							vecStr4.push_back(" ");
							break;
						}
					}
					break;
			}
		}
	}
	//Soedinaiem vektora v obshii po povrastaniy kol-va simvolov
	cout << endl;
	vector<string>vecStr32(5*(vecStr1.size() + vecStr3.size() + vecStr4.size() + vecStr5.size()));
	for (int i = 0; i < 5; i++)
	{
		switch (i+1)
		{
			case 1:
			{
				for (int i = 0; i < N+5; i++) {
					if (vecStr1.size() == i)
					{
						break;
					}
					vecStr32[i] = vecStr1[i];
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < N+5; i++) {
					if (vecStr5.size() == i)
					{
						break;
					}
					vecStr32[6+i] = vecStr5[i];
				}
				break;
			}
			case 3:
			{
				for (int i = 0; i < N+5; i++) {
					if (vecStr3.size() == i)
					{
						break;
					}
					vecStr32[11+i] = vecStr3[i];
				}
				break;
			}
			case 4:
			{
				for (int i = 0; i < N+5; i++) {
					if (vecStr4.size() == i)
					{
						break;
					}
					vecStr32[16+i] = vecStr4[i];
				}
				break;
			}
		}
	}
	//Vivodim 
	for (int y = 0; y<vecStr32.size(); ++y)
	{
		for (int x = 0; x<vecStr32[y].length(); ++x)
		{
			cout << vecStr32[y][x];
		}
	}
	cout << endl;

	system("pause");
	return 0;

}