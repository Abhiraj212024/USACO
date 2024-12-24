#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int linear_search(string v, char element){
    for(size_t i{0}; i < v.size(); i++){
        if(v.at(i) == element){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<string> data (10, "**********");
    int x{0}, y{0};
    //Taking input
    cout << "Enter coordinates of B separated by a space: ";
    cin >> x >> y;
    (data[y])[x] = 'B';
    cout << "Enter coordinates of R separated by a space: ";
    cin >> x >> y;
    (data[y])[x] = 'R';
    cout << "Enter coordinates of L separated by a space: ";
    cin >> x >> y;
    (data[y])[x] = 'L';

    //finding coordinates
    int b_x{0}, b_y{0}, r_x{0}, r_y{0}, l_x{0}, l_y{0};
    int answer{0};
    for(short y{0}; y < 10; y++){
        int x = linear_search(data[y], 'B');
        if (x != -1){
            b_x = x;
            b_y = y;
        }
    }
    for(short y{0}; y < 10; y++){
        int x = linear_search(data[y], 'R');
        if (x != -1){
            b_x = x;
            b_y = y;
        }
    }
    for(short y{0}; y < 10; y++){
        int x = linear_search(data[y], 'L');
        if (x != -1){
            b_x = x;
            b_y = y;
        }
    }
    //computing
    if(b_x == l_x == r_x){ //If same column
        if(abs(b_y-l_y) < (abs(b_y-r_y) + abs(r_y-l_y))){
            answer = abs(b_y - l_y) - 1;
        }else{
            answer = abs(b_y - l_y) + 2;
        }
    }else if(b_y == l_y == r_y){
        if(abs(b_x-l_x) < (abs(b_x-r_x) + abs(r_x-l_x))){
            answer = abs(b_x - l_x) - 1;
        }else{
            answer = abs(b_x - l_x) + 2;
        }
    }else{
        answer = abs(b_x-l_x) + abs(b_y - l_y) -1;
    }
    cout << "The answer is: " << answer;
    return 0;
}