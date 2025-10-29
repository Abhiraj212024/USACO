#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Event {
    int t, x, y;
};

int main(){
    int N, T;
    cin >> N >> T;
    string final_infected;
    cin >> final_infected;

    vector<Event> events(T); // {time, cow1, cow2}

    for(int i = 0; i < T; i++){
        cin >> events[i].t >> events[i].x >> events[i].y;
    }

    sort(events.begin(), events.end(), [](auto& a, auto& b) { return a.t < b.t; });

    int min_k = INT_MAX;
    int max_k = INT_MIN;
    int num_p0 = 0;


    for(int p0 = 1; p0 <= N; p0++){
		if(final_infected[p0-1] == '0') continue;
		// this cow can never be p0

        bool valid_p0 = false;
		//try all possible K
		
		for(int k = 0; k <= T; k++){
			vector<int> infected(N+1, 0);
			vector<int> spread_count(N+1, 0);
			
            
			infected[p0 - 1] = 1;

			// there can be a spread if either is infected and their spread_count is less than k
			for(auto& e : events){
				int x = e.x, y = e.y;

				if(infected[x-1] && spread_count[x-1] < k){
					spread_count[x-1]++;
					infected[y-1] = 1;
				}else if(infected[y-1] && spread_count[y-1] < k){
					spread_count[y-1]++;
					infected[x-1] = 1;
				}
			}
			//create a string for the result of the simulation
			string result = "";
			for(int i = 1; i <= N; i++){
				result += ((infected[i-1] ? '1' : '0'));
			}

			if(result == final_infected){
				valid_p0 = true;
				min_k = min(min_k, k);
				max_k = max(max_k, k); 
			}
		}
        if(valid_p0) num_p0++;
		
    }

    if(max_k == T){
        cout << num_p0 << " " << min_k << " " << "Infinity" << endl;
    }else{
        cout << num_p0 << " " << min_k << " " << max_k << endl;
    }

    return 0;
}
