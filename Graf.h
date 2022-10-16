
/**
* @brief this header file contains graf class
*
* @author Mateusz Dudulski and Izabela Openchowska
* @date 15-04-2016
* @version 1.00
* @copyright Mateusz Dudulski and Izabela Openchowska

*/


#pragma once
#include<iostream>

#define MAX 50
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include "DLLDefines.h"


using namespace std;




PRZESZUKIWANIEGRAFU_EXPORT class Graf{

private:
	/// \brief Number of graph vertex
int	ilosc_wierzcholkow;

/// \brief graph vertex of the starting algorithm

int wierzcholek_poczatkowy;
/// \brief Adjacency matrix where are stored data about connections vertex
public:
int macierz[MAX][MAX];


/// \brief this method takes the arguments in order vertices, edges. Collected data converts to adjacency matrix. Then execute the algorytm and finaly save the map 1. The order of the vertices 2. Colors of vertices.
PRZESZUKIWANIEGRAFU_EXPORT void PrzeszukiwanieGrafu(map<string, vector<int> > nodMap, map < pair<string, string>, pair<int,string >> GraphMaps);


/// \brief  stack is an abstract data type to collect the vertex
stack < int > stos;

/// \brief queue is an abstract data type to collect the vertex
queue < int > kolejka;

/// \brief queue is an abstract data type to collect the vertex
queue < int > odwiedzone;


///  \brief this method print on the screen the vertex that have already been visited
void wypisz_odwiedzone();
/// \return true if graph vertex was visited or false when was't
bool sprawdz_czy_odwiedzone(int x);
///  \brief this method print on the screen the vertex that have already been on the stack
void wypisz_stos();

/// \return returns graph vertex which have not been visited yet
int zwroc_wierzcholek_nieodwiedzony();

///  \brief this method scan the adjacency matrix from the text file
void wczytaj_dane();

///  \brief this method print to the file the list of vertex in order from the algorithm
void zapisz_do_pliku();

/// \brief  default constructor
Graf(int ilosc_wierzcholkow = 6, int wierzcholek_poczatkowy = 2) {
	this->ilosc_wierzcholkow = ilosc_wierzcholkow;
	this->wierzcholek_poczatkowy = wierzcholek_poczatkowy;
}

/// \brief  is used to set the value of a private attribute ilosc_wierzcholkow
void setilosc_wierzcholkow(int ilosc_wierzcholkow)
{
	this->ilosc_wierzcholkow = ilosc_wierzcholkow;
}
/// \brief  is used to get the value of a private attribute ilosc_wierzcholkow
int getilosc_wierzcholkow()
{
	return ilosc_wierzcholkow;
}
/// \brief  is used to set the value of a private attribute wierzcholek_poczatkowy
void setwierzcholek_poczatkowy(int wierzcholek_poczatkowy)
{
	this->wierzcholek_poczatkowy = wierzcholek_poczatkowy;
}
/// \brief  is used to get the value of a private attribute wierzcholek_poczatkowy
int getwierzcholek_poczatkowy()
{
	return wierzcholek_poczatkowy;
}

};

