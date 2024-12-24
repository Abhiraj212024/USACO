#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int m{}, n{};
    cout << "Enter n and m: ";
    cin >> n >> m;
    vector<vector<int>> ideal;
    int length_of_n{}, limit{}, speed{}, ideal_pointer{0}, length_of_m{}, distance{0}, deficit{}, max_deficit;
    for(int i{0}; i < n; i++){
        cout << "Enter length and speed limit: ";
        cin >> length_of_n >> limit;
        distance += length_of_n;
        vector<int> buffer {distance, limit};
        ideal.push_back(buffer);
    }
    distance = 0;
    for(int i{0}; i < m; i++){
        cout << "Enter length and speed: ";
        cin >> length_of_m >> speed;
        distance += length_of_m;
        while(((ideal.at(ideal_pointer)).at(0) < distance) && ideal_pointer < n){
            ideal_pointer++;
        }
        deficit = (ideal.at(ideal_pointer)).at(1) - speed;
        max_deficit = max(max_deficit, deficit);
    }
    cout << "The maximum deficit is: " << max_deficit;
    return 0;
}