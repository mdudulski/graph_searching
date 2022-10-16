/**
* @brief This file contains auxiliary functions
*
* @author Mateusz Dudulski and Izabela Openchowska
* @date 15-04-2016
* @version 1.00
* @copyright Mateusz Dudulski and Izabela Openchowska

*/


#include<iostream>
#include"Graf.h"
#include"DFS.h"
#include"BFS.h"
#include"General.h"
#include"DLLDefines.h"
#include<fstream>
#include<cstdlib>
#include <sstream>

#include <stack>   // biblioteka zawierajaca stos
#include <queue>   // biblioteka zawierajaca kolejke
using namespace std;

#define MAX 25

 void  Graf  :: PrzeszukiwanieGrafu(map<string, vector<int> > nodMap,
									map<pair<string, string>, pair<int, string >> GraphMaps)
{
	ilosc_wierzcholkow = nodMap.size();

	for (int i = 0; i < ilosc_wierzcholkow; i++)
	{
		for (int j = 0; j < ilosc_wierzcholkow; j++)
			macierz[i][j] = 0;
	}

		for (map<pair<string, string>, pair<int, string >>::iterator its = GraphMaps.begin(); its != GraphMaps.end(); ++its)
		{
			const char * str = its->first.first.c_str();
			const char * str2 = its->first.second.c_str();

			macierz[str[0]-'A'][str2[0] - 'A'] = 1;

				if (its->second.second == "0")
				{
					macierz[str[0] - 'A'][str2[0] - 'A'] = 1;
					macierz[str2[0] - 'A'][str[0] - 'A'] = 0;
				}

				if (its->second.second == "1")
				{
					macierz[str2[0] - 'A'][str[0] - 'A'] = 1;
					macierz[str[0] - 'A'][str2[0] - 'A'] = 0;
				}

				if (its->second.second == "2")
				{
					macierz[str2[0] - 'A'][str[0] - 'A'] = 1;
					macierz[str[0] - 'A'][str2[0] - 'A'] = 1;
				}
	}

		for (int i = 0; i < ilosc_wierzcholkow; i++)
		{
			for (int j = 0; j < ilosc_wierzcholkow; j++)
				cout << macierz[i][j] << " ";
			cout << "\n";
		}

		DFS(*this);
		int i = 0;
		this->wypisz_odwiedzone();

		queue < int > kopia1 = odwiedzone;
		vector<int> kolor;
		int x = 50;
		while (!kopia1.empty())
		{
		 char x = kopia1.front() + 'A';
		 string str = string(1, x);
			nodMap[str].push_back(i++);

			kolor.push_back(x);
			kolor.push_back(x);
			kolor.push_back(x);
			nodMap[str] = kolor;

			kopia1.pop();
			kolor.clear();

			x = x + 50;
			if (x > 255)
				x = 255;

		}

		system("pause");
}


void Graf::wczytaj_dane() // wczytywanie macierzy z pliku
{
	int j, i;

	fstream plik;
	plik.open("wejscie.txt", ios::in);

	if (plik.good() == false)
	{
		cout << "Plik nie istnieje";
		exit(0);
	}


	plik >> ilosc_wierzcholkow;
	plik >> wierzcholek_poczatkowy;

	while (!plik.eof())
	{
		for (i = 0; i<ilosc_wierzcholkow; i++)
		{
			for (j = 0; j<ilosc_wierzcholkow; j++)
			{
				plik >> macierz[i][j];
			}
		}
	}
	plik.close();
}



void Graf::wypisz_stos()    // wypisz na konsole stos
{
	stack <int> kopia = stos;
	printf("\nAktualny stos: ");

	while (!kopia.empty())
	{
		printf("%d ", kopia.top());  //top - zwraca wartosc szczytowego elementu na stosie
		kopia.pop();   //pop - zdjecie istniejacego elementu ze szczytu stosu
	}
	printf("\n");
}

void Graf::wypisz_odwiedzone()    // wypisz na konsole odwiedzone
{
	queue < int > kopia1 = odwiedzone;
	printf("\nOdwiedzone: ");

	while (!kopia1.empty())   //empty - informacja czy stos jest pusty
	{
		printf("%d ", kopia1.front());
		kopia1.pop();
	}
	printf("\n");
}

void Graf::zapisz_do_pliku()
{


	fstream plik;
	plik.open("wyjscie.txt", ios::out | ios::app);
	queue < int > kopia1 = odwiedzone;

	while (!kopia1.empty())   //empty - informacja czy stos jest pusty
	{
		plik << kopia1.front(); /* zapisz nasz ³añcuch w pliku */
		kopia1.pop();
	}
	plik << endl;
	plik.close(); /* zamknij plik */

}


bool Graf::sprawdz_czy_odwiedzone(int x)
{
	//printf("sprawdzam czy odwiedzone i = %d \n",x);
	queue < int > kopia1 = odwiedzone;

	while (!kopia1.empty())
	{
		if (x == kopia1.front())
		{
			//printf("sprawdz_czy_odwiedzone zwracam true\n");
			return true;
		}
		kopia1.pop();
	}
	//printf("sprawdz_czy_odwiedzone zwracam false\n");
	return false;
}

int Graf::zwroc_wierzcholek_nieodwiedzony()
{
	int liczba = 0; // liczba, od której próbujemy zacz¹c odwiedzanie w razie, gdy stos jest pusty

	while (sprawdz_czy_odwiedzone(liczba) == true)
	{
		liczba++;
	}
	//printf("jestem sobie w funkcji zwroc_wierzcholek_nieodwiedzony ");
	return liczba;
}


