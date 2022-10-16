
/**
* @brief this file contains main 
*
* @author Mateusz Dudulski and Izabela Openchowska
* @date 15-04-2016
* @version 1.00
* @copyright Mateusz Dudulski and Izabela Openchowska

*/

#include<iostream>					
#include"Graf.h"
using namespace std;
#include"DFS.h"
#include"BFS.h"
#include"General.h"
#include"map"


int main()
{

Graf g1,g2,g3;

map<string, vector<int> > nodMaps;
map < pair<string, string>, pair<int, string >> GraphMaps;

vector<int> kolor;
kolor.push_back(100);
kolor.push_back(100);
kolor.push_back(100);
nodMaps["A"] = kolor;
nodMaps["B"] = kolor;
nodMaps["C"] = kolor;
nodMaps["D"] = kolor;
nodMaps["E"] = kolor;
nodMaps["F"] = kolor;

pair<string, string> pary1("A", "B");
pair<string, string> pary2("A", "C");

pair<string, string> pary4("B", "E");
pair<string, string> pary5("C", "D");
pair<string, string> pary6("C", "F");
pair<string, string> pary7("D", "E");
pair<string, string> pary8("B", "A");
pair<string, string> pary9("C", "A");
pair<string, string> pary10("D", "B");
pair<string, string> pary11("D", "C");
pair<string, string> pary12("D", "E");
pair<string, string> pary13("E", "B");
pair<string, string> pary14("F", "C");


pair<int, string> wagi (1, "1");
GraphMaps[pary1] = wagi;
GraphMaps[pary2] = wagi;

GraphMaps[pary4] = wagi;
GraphMaps[pary5] = wagi;
GraphMaps[pary6] = wagi;
GraphMaps[pary7] = wagi;
GraphMaps[pary8] = wagi;
GraphMaps[pary9] = wagi;
GraphMaps[pary10] = wagi;
GraphMaps[pary11] = wagi;
GraphMaps[pary12] = wagi;
GraphMaps[pary13] = wagi;
GraphMaps[pary14] = wagi;


g1.PrzeszukiwanieGrafu(nodMaps,GraphMaps);
//g1.wczytaj_dane();

/*
DFS(g1);
g1.zapisz_do_pliku();

g2.wczytaj_dane();
BFS(g2);
g2.zapisz_do_pliku();


g3.wczytaj_dane();
General(g3);
g3.zapisz_do_pliku();
*/
}