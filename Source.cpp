/**************
Решите, используя алгоритмы и лямбда-выражения:
1. Массив городов заполняется городами со случайными названиями и случайным населением.
2. Распечатайте все города-миллионники
3. Отсортируйте города по названию. Распечатайте
4. Отсортируйте города по населению. Распечатайте
************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

	int randomPopulation() {
		return rand() % 1000000 + 990000;
	}
	string randomName() {
		int length = rand() % 3 + 5;
		string tmp;
		tmp = (char)(rand() % 25 + 65);
		for (int i = 0; i < length; i++)
			tmp += rand() % 26 + 97;
		return tmp;
	}
class  City {
	string name;
	int population;
public:
	City(string name,  int population)
		:name(name), population(population) {}
	const string& getName() const { return name; }
	int getPopulation() const { return population; }
	
	void printBln(const pair<string, int>& cityPopulations) {
		if(cityPopulations.second >=1000000)
			cout << cityPopulations.first << ": " << cityPopulations.second << endl;
	}
};

int main() {
	vector<City> cities{
		{ randomName(), randomPopulation() },
		{ randomName(), randomPopulation() },
		{ randomName(), randomPopulation() },
		{ randomName(), randomPopulation() },
		{ randomName(), randomPopulation() },
	};
	for_each(cities.begin(), cities.end(),
		[](City city) { if (city.getPopulation()>1000'000) cout << city.getName() << ' ' << city.getPopulation() << endl; });
	cout << endl;
	sort(cities.begin(), cities.end(),
		[](City a, City b) { return a.getName() < b.getName(); });
	for_each(cities.begin(), cities.end(),
		[](City city) { cout << city.getName() << ' ' << city.getPopulation() << endl; });
	cout << endl;

	sort(cities.begin(), cities.end(),
		[](City a, City b) { return a.getPopulation() > b.getPopulation(); });
	for_each(cities.begin(), cities.end(),
		[](City city) { cout << city.getName() << ' ' << city.getPopulation() << endl; });

}

