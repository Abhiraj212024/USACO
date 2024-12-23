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
    int bronze_init{0}, bronze_final{0}, silver_init{0}, silver_final{0}, gold_init{0}, gold_final{0}, plat_init{0}, plat_final{0};
    cout << "Enter bronze initial and final separated by space: ";
    cin >> bronze_init >> bronze_final;
    cout << "Enter silver initial and final separated by space: ";
    cin >> silver_init >> silver_final;
    cout << "Enter gold initial and final separated by space: ";
    cin >> gold_init >> gold_final;
    cout << "Enter platinum initial and final separated by space: ";
    cin >> plat_init >> plat_final;
    int gold_to_platinum {plat_final - plat_init};
    int silver_to_gold {gold_final - gold_init + gold_to_platinum};
    int bronze_to_silver {silver_final - silver_init + silver_to_gold + gold_to_platinum};
    cout << bronze_to_silver << "\n" << silver_to_gold << "\n" << gold_to_platinum;
    return 0;
}