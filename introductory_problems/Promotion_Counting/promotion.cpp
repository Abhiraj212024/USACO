/*
Bessie the cow is helping Farmer John run the USA Cow Olympiad (USACO), an on-line contest where participants answer challenging questions to demonstrate their mastery of bovine trivia.
In response to a wider range of participant backgrounds, Farmer John recently expanded the contest to include four divisions of difficulty: bronze, silver, gold, and platinum. All new participants start in the bronze division, and any time they score perfectly on a contest they are promoted to the next-higher division. It is even possible for a participant to be promoted several times within the same contest. Farmer John keeps track of a list of all contest participants and their current divisions, so that he can start everyone out at the right level any time he holds a contest.
When publishing the results from his most recent contest, Farmer John wants to include information on the number of participants who were promoted from bronze to silver, from silver to gold, and from gold to platinum. However, he neglected to count promotions as they occurred during the contest. Bessie, being the clever bovine she is, realizes however that Farmer John can deduce the number of promotions that occurred solely from the number of participants at each level before and after the contest. Please help her perform this computation!
*/

//INPUT FORMAT:
/*
Input consists of four lines, each containing two integers in the range 0..1,000,000. 
The first line specifies the number of bronze participants registered before and after the contest. 
The second line specifies the number of silver participants before and after the contest. 
The third line specifies the number of gold participants before and after the contest. 
The last line specifies the number of platinum participants before and after the contest.
*/
//OUTPUT FORMAT:
/*
Please output three lines, each containing a single integer. The first line should contain the number of participants 
who were promoted from bronze to silver. The second line should contain the number of participants who were promoted 
from silver to gold. The last line should contain the number of participants who were promoted from gold to platinum.
*/

//EXAMPLE:
/*
INPUT:
    1 2
    1 1
    1 1
    1 2 
OUTPUT:
    1
    1
    1
REASON: In this example, 1 participant was registered in each division prior to the contest. 
        At the end of the contest, 2 participants were registered in bronze and platinum. 
        One way this could have happened is that 2 new participants joined during the contest; one was promoted 
        all the way to platinum, and the other stayed in bronze.
*/
#include <iostream>

using namespace std;

int main(){
    int a0, a1, a2, a3;
    int b0, b1, b2, b3;
    vector<int> ans;
    cin >> b0 >> a0;
    cin >> b1 >> a1;
    cin >> b2 >> a2;
    cin >> b3 >> a3;

    int bs{0}, sg{0}, gp{0};
    gp = a3-b3;
    sg = a2-b2+gp;
    bs=a1-b1+sg;

    cout << "\n" << bs << "\n" << sg << "\n" << gp;

    return 0;
}