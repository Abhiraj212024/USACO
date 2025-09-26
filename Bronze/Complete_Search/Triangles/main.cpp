#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for(int i = 0; i < n; i++){
        int first, second;
        cin >> first >> second;
        pair<int, int> buff = {first, second};
        points.push_back(buff);

    }

    int max_area = 0;

    for(int i = 0; i < n; i++){
        int a = 0;
        int b = 0;
        for(int j = i+1; j < n; j++){
            if(points[i].second == points[j].second){
                b = abs(points[i].first - points[j].first);
                for(int k = 0; k < n; k++){
                    if(points[k].first == points[i].first){
                        a = abs(points[k].second - points[i].second);
                        max_area = max(max_area, (a*b));
                    }
                    if(points[k].first == points[j].first){
                        a = abs(points[k].second - points[j].second);
                        max_area = max(max_area, (a*b));
                    }
                }
            }
        }
    }

    cout << max_area << "\n";

    return 0;
}