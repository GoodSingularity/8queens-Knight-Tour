#include <bits/stdc++.h>
#include <iostream>
#include <tuple>
#define N 8
using namespace std;

//Reguły Warnsdorffa:

/*
Zaczynamy z jakiejkolwiek pozycji na szachownicy.
Ruszamy sie do sasiadujacych nie odwiedzonych pol z minimalną liczbą sposobów 

( minimalna liczba nieodwiedzonych sąsiadujących)

Algorytm Warnsdorfa sprawdza czy
*/
//Szachownica, 64 elementów = 8x8
int a[N*N];
//Wszystkie mozliwe ruchy w ksztalcie litery L
static int movesX[N] = {1,1,2,2,-1,-1,-2,-2};
static int movesY[N] = {2,-2,1,-1,2,-2,1,-1};

//Sprawdza czy mozna polozyc tu knighta.
bool isEmpty(int a[], int x, int y)
{
	return ((x >= 0 && y >= 0) && (x < N && y < N))&& (a[y*N+x] < 0);
}

//Zwraca liczbe sąsiadujących pustych kwadratów z (x, y)
int getDegree(int a[], int x, int y)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
		if (isEmpty(a, (x + movesX[i]), (y + movesY[i])))
			count++;

	return count;
}
//Inicjalizacja tablicy, kazdy element = -1.
void initArray(){
	for (int i = 0; i< N*N; ++i)
		a[i] = -1;
};
//Minimalna liczba sposobow.
tuple<int, int, int, int> MinimumDeg(int a[], int *x, int *y){
	int idx = -1, c, min_deg = (N+1), newX, newY;
	//Losuje startowa pozycje
	int start = rand()%N;
	//Petla
	for (int count = 0; count < N; ++count)
	{
		int i = (start + count)%N;
		newX = *x + movesX[i];
		newY = *y + movesY[i];
        //Sprawdza czy nowe kordynaty sa puste
        // i czy to najmniejsza liczba sposobow na poruszanie sie
		if ((isEmpty(a, newX, newY)) && (c = getDegree(a, newX, newY)) < min_deg)
		{
			idx = i;
			min_deg = c;
		}
	}
	return {idx,min_deg,newX, newY};
	}
//Kolejny ruch
bool nextMove(int a[], int *x, int *y)
{
	auto [idx, min_deg, newX, newY] = MinimumDeg(a,x,y);
	// Jezeli nie mozna znalezc nastepnej komorki
	if (idx == -1)
		return false;
    //Zapisz koordynaty kolejnego punktu
	newX = *x + movesX[idx], newY = *y + movesY[idx];
	// Oznacz nastepny ruch
	a[newY*N + newX] = a[(*y)*N + (*x)]+1;
	// aktualizuj kolejny punkt.
	*x = newX, *y = newY;
	return true;
}

//Sprawdza sąsiadujące pola.
//Jezeli rycez konczy na polu ktore jest blisko odlegle od jego pierwszego ruchu, closed tour.
bool isNeighbour(int x, int y, int xx, int yy)
{
	for (int i = 0; i < N; ++i)
		if (((x+movesX[i]) == xx)&&((y + movesY[i]) == yy))
			return true;
	return false;
}

/*
Tworzy kombinacje ruchow wedlug warnsdorffa. Zwraca falsz jeszeli nie jest mozliwe
Algorytm o wiele szybszy niz backtracking
*/
bool findSolution()
{
	// Filling up the chessboard matrix with -1's
    initArray();
    //wylosowane pozycje poczatkowe
	int sx = rand()%N, sy = rand()%N;
	int x = sx, y = sy;
	//oznacz pierwszy ruch
	a[y*N+x] = 1;.

	//wybieraj kolejne punkty wedlug algorytmu Warnsdorffa
	for (int i = 0; i < N*N-1; ++i)
		if (nextMove(a, &x, &y) == 0)
			return false;

	//Sprawdza czy konczy sie na punkcie startowym
	if (!isNeighbour(x, y, sx, sy))
		return false;
    //Wypisuje tablice
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			printf("%d\t",a[j*N+i]);
		printf("\n");
	}
	return true;
}

int main()
{
	srand(time(NULL));

	while (!findSolution())
	{
	;
	}

	return 0;
}
