// Sortowanie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"//ten nagłówek tylko dla visual studio
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//to dla vectorów więc nie musisz przekazywać wielkości tablicy (vectory to takie lepsze tablice)
vector<int> bubbleSort(vector<int> v)
{
	for (int i = 0; i < v.size() - 1; i++)
		for (int j = 0; j < v.size() - i - 1; j++)
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
	return v;
}
// to dla zwykłych tablic
int* bublesort2(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	return arr;
}

bool anagram(string a, string b)
{
	if (a.size() != b.size())
		return false;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return false;
		
	}
	return true;
}

int main()
{
	//							anagramy
	
	string a, b;
	cin >> a >> b;
	if (anagram(a, b))
		cout << "tak" << endl;
	else
		cout << "nie" << endl;
		


	
	//							 Sortowanie bąbelkowe
	//to dla vectorów 
	vector<int> v = { 3,2,1 };


	//int arr[] = { 3,2,1 };
	//vector<int> v(arr, arr + sizeof(arr) / sizeof(int)); to dla codeblocks i dla świetnego cpp98
	
	vector<int>vec = bubbleSort(v);
	cout << "Posortowany vector:" << endl;
	for (int i = 0; i<a.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
	// tu dla zwykłych tablic
	
	cout << "Posortowana tablica" << endl;
	int t[3] = { 5,32,321 };
	int dlugosc = sizeof(t) / sizeof(t[0]);
	int *t2 = bublesort2(t, dlugosc);
	for (int i = 0; i < dlugosc; i++)
		cout << t2[i] << " ";
	cout << endl;
	




}


