#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main(){
	unordered_map<string, string> tracker;
	unordered_map<string, int> zodiac;
	unordered_map<string, int> age;
	vector<string> animals = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
	int size = animals.size();
	for(int i = 0; i < size; i++){
		zodiac[animals[i]] = i;
	}
	tracker["Bessie"] = "Ox";
	age["Bessie"] = 0;
	int n;
	cin >> n;
	for(int i{}; i < n; i++){
		vector<string> sentence(8);
		for(int j{}; j < 8; j++){
			cin >> sentence[j];
		}

		string cowA = sentence[0];
		string cowB = sentence[7];
		if(sentence[3] == "previous"){
			string animal = sentence[4];
			int offset = (zodiac[tracker[cowB]] <= zodiac[animal]) ? (12 - (zodiac[animal] - zodiac[tracker[cowB]])) : (zodiac[tracker[cowB]] - zodiac[animal]);
			tracker[cowA] = animal;
			age[cowA] = age[cowB] - offset;
		}else{
			string animal = sentence[4];
			int offset = (zodiac[tracker[cowB]] < zodiac[animal]) ? (zodiac[animal] - zodiac[tracker[cowB]])  : 12 - (zodiac[tracker[cowB]] - zodiac[animal]);
			tracker[cowA] = animal;
			age[cowA] = age[cowB] + offset;
		}
	}
	cout << abs(age["Elsie"] - age["Bessie"]) << "\n";
	return 0;
}
