/**
* @brief This file contains algorithm that searches the graph from the lowest index of vertex  to the biggest index
*
* @author Mateusz Dudulski and Izabela Openchowska
* @date 15-04-2016
* @version 1.00
* @copyright Mateusz Dudulski and Izabela Openchowska

*/



#include<iostream>
#include"Graf.h"

#include<fstream>
#include<cstdlib>
#include <stack>   // biblioteka zawierajaca stos
#include <queue>   // biblioteka zawierajaca kolejke
using namespace std; 

void General(Graf &g)
{
	int i, j;
	int wierzcholek = g.getwierzcholek_poczatkowy();

	for (i = 0; i<g.getilosc_wierzcholkow(); i++)
	{
		printf("\nAktualnie odwiedzany %d\n", wierzcholek);

		

		g.odwiedzone.push(wierzcholek); 	// wrzucamy do kolejki element, który zostal odwiedzony 

		g.wypisz_odwiedzone();

		if (g.odwiedzone.size()<g.getilosc_wierzcholkow())  // przypadek w ktorym stos jest pusty i bierzemy losowy element 
		{
			wierzcholek = g.zwroc_wierzcholek_nieodwiedzony();   // do wiersza zapisujemy 
			printf("\n Do kolejnej iteracji wybieramy pierwszy nieodwiedzony wierzcholek: %d\n\n", wierzcholek);
		}

		
		system("pause");
	}
 }