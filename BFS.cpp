/**
* @brief This file contains algorithm BFS
*
* @author Mateusz Dudulski and Izabela Openchowska
* @date 15-04-2016
* @version 1.00
* @copyright Mateusz Dudulski and Izabela Openchowska

*/

#include<iostream>
#include"Graf.h"
#include"BFS.h"
#include<fstream>
#include<cstdlib>
#include <stack>   // biblioteka zawierajaca stos
#include <queue>   // biblioteka zawierajaca kolejke
using namespace std;



void BFS(Graf &g)
{
	int i, j;
	int wierzcholek = g.getwierzcholek_poczatkowy();
	for (i = 0; i<g.getilosc_wierzcholkow(); i++)
	{
		//printf("\nfor nr = %d\n", i);
		printf("\nAktualnie odwiedzany %d\n", wierzcholek);

		for (j = g.getilosc_wierzcholkow() - 1; j >= 0; j--)    // przechodzi przez macierz sasiedztwa we wskazanym wierszu
		{
			if (g.macierz[wierzcholek][j]>0)
			{
				if (g.sprawdz_czy_odwiedzone(j) == false)
				{
					g.kolejka.push(j);
					printf(" Liczba %d trafila do kolejki.\n", g.kolejka.back());
				}
			}
		}

		g.odwiedzone.push(wierzcholek); 	// wrzucamy do kolejki element, który zostal odwiedzony 

		g.wypisz_odwiedzone();

		if (g.kolejka.empty() && g.odwiedzone.size()<g.getilosc_wierzcholkow())  // przypadek w ktorym stos jest pusty i bierzemy losowy element 
		{
			wierzcholek = g.zwroc_wierzcholek_nieodwiedzony();   // do wiersza zapisujemy 
			printf("\nKolejka jest pusta, do kolejnej iteracji wybieramy losowa liczbe: %d\n\n", wierzcholek);
		}

		if (!g.kolejka.empty())   // stos nie jest pusty a wiêc bierzemy pierwszy element ze stosu
		{
			wierzcholek = g.kolejka.front();  // liczba, któr¹ przypisujemy do nastêpnej iteracji 
			printf("\nLiczba brana z kolejki %d \n\n", g.kolejka.front());
			g.kolejka.pop();   // operacja zabiera ze stosu liczbe
		}
		system("pause");
	}
}