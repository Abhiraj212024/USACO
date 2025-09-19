#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;

    int highest[101] = {};
    char cow[101] = {'\0'};
    int cow_previous[3] = {7, 7, 7};

    for(int i = 0; i < n; i++){
        int day;
        int deviation;
        string name;

        cin >> day >> name >> deviation;

        if(deviation != 0){
            highest[day-1] = deviation;
            cow[day-1] = name[0];
        }
    }
    int prev_highest = 0;
    char prev_cow = '\0';
    int change = 0;
    for(int i = 1; i < 100; i++){
        if(highest[i] > prev_highest && cow[i] != prev_cow){
            change++;
            prev_highest = highest[i];
        }else if(cow[i] == prev_cow && highest[i] < prev_highest){
            change++;
            prev_highest = (highest[i] > 0) ? highest[i] : 0;
        }
    }

    cout << change << "\n";

    return 0;
}