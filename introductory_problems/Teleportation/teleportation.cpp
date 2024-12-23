//Problem Statement: 

/*
One of the farming chores Farmer John dislikes the most is hauling around lots of cow manure. In order to streamline this process, he comes up with a brilliant invention: the manure teleporter! Instead of hauling manure between two points in a cart behind his tractor, he can use the manure teleporter to instantly transport manure from one location to another.
Farmer John's farm is built along a single long straight road, so any location on his farm can be described simply using its position along this road (effectively a point on the number line). A teleporter is described by two numbers x and y, where manure brought to location x can be instantly transported to location y, or vice versa.
Farmer John wants to transport manure from location a to location b, and he has built a teleporter that might be helpful during this process (of course, he doesn't need to use the teleporter if it doesn't help). Please help him determine the minimum amount of total distance he needs to haul the manure using his tractor 
*/

//Input Format: 
/*
The first and only line of input contains four space-separated integers: a and b, describing the start and end locations, 
followed by x and y, describing the teleporter. All positions are integers in the range 0…100, and they are not necessarily 
distinct from each-other.
*/

//Output Format: 
/*
Print a single integer giving the minimum distance Farmer John needs to haul manure in his tractor.
*/

//Example:
/*
INPUT : 3 10 8 2
OUTPUT: 3
REASON: In this example, the best strategy is to haul the manure from position 3 to position 2, teleport it to position 8, 
        then haul it to position 10. The total distance requiring the tractor is therefore 1 + 2 = 3.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    int a{0}, b{0}, x{0}, y{0};
    cout << "Enter a b x y separated by a space respectively: ";
    cin >> a >> b >> x >> y;
    int direct_distance {abs(b-a)};
    int nearest_to_a = min(abs(a-x), abs(a-y));
    int nearest_to_b = min(abs(b-x), abs(b-y));
    int answer = min(direct_distance, (nearest_to_a + nearest_to_b));
    cout << "Minimum distance is: " << answer << endl;
    return 0;
}