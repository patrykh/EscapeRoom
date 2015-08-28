// EscapeRoom.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct element_listy
{
	element_listy * nastepny;
	int v;
};

int main()
{
	//Dane
	// numer pokoju gdzi jest J23
	// gdzie jest Bruner
	// gdzie jest wyjœcie

	// liczbaPokoi - ca³kowita liczba pokoi

	int j24, 
		bruner, 
		wyjscie,
		liczbaPokoi,
		** macierz;
	bool * visited;

	element_listy *q, *glowa, *ogon;

	//wczytanie danych
	cin >> j24 >> bruner >> wyjscie;
	cin >> liczbaPokoi;
	
	visited = new bool[liczbaPokoi];

	//inicjacja tablicy dynamicznej dla macierzy s¹siedztwa
	macierz = new int *[liczbaPokoi];
	for (int i = 0; i < liczbaPokoi; i++){
		macierz[i] = new int[liczbaPokoi];
	}

	//wype³nienie macierzy s¹siedztwa
	for (int i = 0; i < liczbaPokoi; i++){
		for (int j = 0; j < liczbaPokoi; j++){
			cin >> macierz[i][j];
		}
	}

	for (int i = 0; i < liczbaPokoi; i++){
		visited[i] = false;
	}

	// 2 grafy ??
	// BFS

	q = new element_listy;
	q->nastepny = NULL;
	q->v = j24;
	glowa = ogon = q;
	cout << q->v;
	visited[j24] = true;

	while (glowa){
		j24 = glowa->v;
		q = glowa;
		cout << "2 " << glowa->v;
		glowa = glowa->nastepny;
		if (!glowa) ogon = NULL;
		delete q;

		for (int i = 0; i < liczbaPokoi; i++){
			if (macierz[j24][i] == 1 || macierz[j24][i] == -1 && visited[i]){
				q = new element_listy; // W kolejce umieszczamy nieodwiedzonych s¹siadów
				q->nastepny = NULL;
				q->v = i;
				if (!ogon) glowa = q;
				else ogon->nastepny = q;
				ogon = q;
				visited[i] = true;
			}
		}
	}

	// Zwalnianie pamiêci
	for (int i = 0; i < liczbaPokoi; i++){
		delete [] macierz[i];
	}
	delete [] macierz;
	delete [] visited;
	
	return 0;
}

