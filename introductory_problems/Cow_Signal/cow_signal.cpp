//Problem Statement:
/*
Bessie and her cow friends are playing as their favorite cow superheroes. 
Of course, everyone knows that any self-respecting superhero needs a signal to call them to action. 
Bessie has drawn a special signal on a sheet of M×N paper (1≤M≤10,1≤N≤10), but this is too small, 
much too small! Bessie wants to amplify the signal so it is exactly K times bigger (1≤K≤10) in each direction.
*/

/*
INPUT:
    First line on input contains M,N,K
    next M rows contain a length N string, collectively describing the picture of the signal
OUTPUT:
    Output KM lines each containing string of length KN
*/

//Example:
//Input:

//5 4 2
//XXX.
//X..X
//XXX.
//X..X
//XXX.

//Output:

// XXXXXX..
// XXXXXX..
// XX....XX
// XX....XX
// XXXXXX..
// XXXXXX..
// XX....XX
// XX....XX
// XXXXXX..
// XXXXXX..

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void vector_init(vector<string> &input, int m){
    string init = "";
    for(int i{0}; i < m; i++){
        cout << "Enter the string: ";
        cin >> init;
        input.push_back(init);
    }
}
int main(){
    int M{0}, N{0}, K{0};
    cout << "Enter M, N, K: ";
    cin >> M >> N >> K;

    vector<string> input;
    vector<string> output;
    string buffer {};
    vector_init(input, M);
    for(auto str : input){
        for(auto c : str){
            for(int i{0}; i < K; i++){
                buffer+=c;
            }
        }
        for(int i{0}; i < K; i++){
            output.push_back(buffer);
        }
        buffer = "";
    }
    for(auto str: output){
        cout << str << endl;
    }
    cout << endl;
    return 0;
}