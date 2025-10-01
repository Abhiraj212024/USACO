#include <iostream>
#include <vector>
using namespace std;

int merges(vector<int> v, int n){
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        total_sum+=v[i];
    }
    vector<int> divisors;
    for(int i = 1; i < total_sum / 2 + 1; i++){
        if(!(total_sum%i)){
            divisors.push_back(i);
        }
    }
    int answer = INT_MAX;
    divisors.push_back(total_sum);
    for(const int& d : divisors){
        int k = 0;
        int curr_sum = 0;
        for(int i = 0; i < n; i++){
            curr_sum += v[i];
            if(curr_sum == d){
                k++;
                curr_sum = 0;
                continue;
            }else if(curr_sum > d){
                k = 0;
                break;
            }
        }
        answer = min(answer, n-k);
    }
    return answer;
}

int main(){
    int t;
    cin >> t;
    vector<int> solutions;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> vec(n);
        
        for(int j = 0; j < n; j++){
            cin >> vec[j];
        }
        solutions.push_back(merges(vec, n));
    }

    for(int i = 0; i < t; i++){
        cout << solutions[i] << "\n";
    }
    return 0;
}