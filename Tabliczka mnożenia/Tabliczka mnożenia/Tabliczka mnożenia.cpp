// Tabliczka mnożenia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdlib>
#include<Windows.h>
#include<limits.h>
#include<time.h>

void wyborTrybu()
{
	std::cout << "wybierz tryb" << "\n";
	std::cout << "1. okreslona ilosc przykladow" << "\n";
	std::cout << "2. do 10 poprawnych odpowiedzi" << "\n";
	std::cout << "3. do pierwszej poprawnej odpowiedzi" << "\n";
}

void wyborPoziomuTrudnosci()
{
	std::cout << "\n";
	std::cout << "Wybierz poziom trudnosci" << "\n";
	std::cout << "1. latwy" << "\n";
	std::cout << "2. trudny" << "\n";
	std::cout << "3. Jerzy Bandziak" << "\n";
}

bool czyPoprawnaOdpowiedz(int liczba1, int liczba2,int odpowiedz)
{
	if (liczba1*liczba2 == odpowiedz)
		return true;
	return false;
}

float ocena(float poprawneOdpowiedzi, float liczbaPrzykladow)
{
	return  poprawneOdpowiedzi / liczbaPrzykladow * 100;
}


int main()
{
	int tryb, poziomTrudnosci, zakres, oczekiwanePoprawneOdpowiedzi, liczba1, liczba2, odpowiedz;
	int poprawneOdpowiedzi = 0;

	bool czyOcena;

	std::cout << "witaj w programie do nauki tabliczki mnozenia" << "\n"<<"\n";
	wyborTrybu();
	std::cin >> tryb;

	switch (tryb)
	{
		case 1: std::cout << "podaj liczbe przykladow" << "\n"; std::cin >>oczekiwanePoprawneOdpowiedzi ; break;
		case 2: oczekiwanePoprawneOdpowiedzi = 10; break;
		case 3: oczekiwanePoprawneOdpowiedzi = 1; break;
		default: std::cout << "Najpierw naucz sie czytac , potem tabliczki mnozenia" << "\n" << "program zamknie sie za 3 sekundy" << "\n"; break;
	}

	wyborPoziomuTrudnosci();
	std::cin >> poziomTrudnosci;

	switch (poziomTrudnosci)
	{
		case 1: zakres =10 ; break;
		case 2: zakres = 100; break;
		case 3: zakres = INT32_MAX; break;
		default: std::cout << "Najpierw naucz sie czytac , potem tabliczki mnozenia" << "\n" << "program zamknie sie za 3 sekundy" << "\n"; break;
	}

	std::cout << "Wystawic ocene?" << "\n" << "0. Nie" << "\n" << "1. Tak" << "\n";
	std::cin >> czyOcena;

	srand(time(NULL));

	while(poprawneOdpowiedzi != oczekiwanePoprawneOdpowiedzi)
	{
		liczba1 = rand() % zakres+1;
		liczba2 = rand() % zakres+1;
		std::cout << liczba1<< '*' << liczba2 << '=';
		std::cin >> odpowiedz;
		if (czyPoprawnaOdpowiedz(liczba1, liczba2, odpowiedz))
			poprawneOdpowiedzi++;
		else if (tryb == 1)
			poprawneOdpowiedzi++;
		

	}
	if (czyOcena)
	{
		std::cout<<ocena(poprawneOdpowiedzi, oczekiwanePoprawneOdpowiedzi);
	}
	

	


	





}

