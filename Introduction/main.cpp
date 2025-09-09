#include <iostream>
using namespace std;

int main(){
    unsigned int input;
    cin >> input;
    char hex_str[10];
    unsigned int shift = 15;
    unsigned int hex3 = (input) & shift;
    unsigned int hex4 = (input >> 4) & shift;
    unsigned int hex5 = (input >> 8) & shift;
    unsigned int hex6 = (input >> 12) & shift;

    hex_str[0] = '0';
    hex_str[1] = 'x';
    hex_str[5] = (hex3 > 9 ? (char) (hex3 + 65 - 10) : (char) hex3);
    hex_str[4] = (hex4 > 9 ? (char) (hex4 + 65 - 10) : (char) hex4);
    hex_str[3] = (hex5 > 9 ? (char) (hex5 + 65 - 10) : (char) hex5);
    hex_str[2] = (hex6 > 9 ? (char) (hex6 + 65 - 10) : (char) hex6);

    hex_str[6] = '\0';

    for(const auto elem : hex_str){
        cout << elem << " ";
    }
    return 0;
}