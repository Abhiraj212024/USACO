#include <iostream>
#include <map>
#include <utility>
using namespace std;


int main(){
    int n;
    cin >> n;
    map<pair<int, int>, int> coordinates;
    vector<int> time_intersections;
    int clock = 0;
    int x = 0;
    int y = 0;
    coordinates[{x, y}] = 0;
    for(int i = 0; i < n; i++){
        char d;
        int s;
        cin >> d >> s;
        for(int j = 1; j <= s; j++){
            if(d == 'N'){
                y++;
            }else if(d == 'S'){
                y--;
            }else if(d == 'E'){
                x++;
            }else{
                x--;
            }
            clock++;
            pair<int, int> temp = {x, y};
            if(coordinates.find(temp) == coordinates.end()){ //non visited coordinate
                coordinates[temp] = clock;
            }else{
                time_intersections.push_back((clock-coordinates[temp]));
                coordinates[temp] = clock; //update it you come back for multiple times
            }
        }
    }

    if(time_intersections.size()){
        int min_element = INT_MAX;
        for(int i = 0; i < time_intersections.size(); i++){
            min_element = min(min_element, time_intersections[i]);
        }

        cout << min_element << "\n";
    }else{
        cout << -1 << "\n";
    }

    return 0;
}