/**************
Решите, используя алгоритмы и лямбда-выражения:
1. Массив городов заполняется городами со случайными названиями и случайным населением.
2. Распечатайте все города-миллионники
3. Отсортируйте города по названию. Распечатайте
4. Отсортируйте города по населению. Распечатайте
************************/
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

string randomName() {
	int length = rand() % 5 + 5;
	string tmp;
	tmp = (char)rand() % 26 + 65;
	for (int i = 0; i < length; i++)
		tmp += rand() % 26 + 97;
	return tmp;
}
int randomPopulation() {
	return rand() % 1000000 + 500000;
}

void printBln(map& cityPopulations) {
	if(cityPopulations.second >=1000000)
		cout << cityPopulations.first << ": " << cityPopulations.second << endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	map<string, float> cityPopulations;

	int countCity = rand() % 20 + 10;
	for(int  i=0; i< countCity; i++)
		cityPopulations.insert_or_assign(randomName(), [] {return rand() % 1000000 + 500000; });

	/*for (const pair<string, int>& cityPopulation : cityPopulations)
		if(pair.second >= 1000000)
			cout << pair.first << ": " << pair.second << endl;*/

	for_each(cityPopulations.begin(), cityPopulations.end(), printBln);
	sort(cityPopulations.begin(), cityPopulations.end(), less<int>());
	for_each(cityPopulations.begin(), cityPopulations.end(), [cityPopulations] {cout << cityPopulations.first << ": " << cityPopulations.second << endl; });
	sort(cityPopulations.begin(), cityPopulations.end(), less<string>());
	for_each(cityPopulations.begin(), cityPopulations.end(), [cityPopulations] {cout << cityPopulations.first << ": " << cityPopulations.second << endl; });

	return 0;
}

