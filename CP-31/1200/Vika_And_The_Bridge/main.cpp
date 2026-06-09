#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
	int t;
	cin >> t; // Read the number of test cases

	while (t--)
	{
		int n, k;
		cin >> n >> k; // Read the number of planks and colors

		vector<int> v(n);
		for (int i = 0; i < n; i++) // O(N)
			cin >> v[i]; // Read the colors of each plank

		vector<int> colours[k + 1]; // Create a vector of vectors to store indices for each color

		for (int i = 1; i <= k; i++) // O(k)
		{
			colours[i].push_back(0); // Initialize each color vector with 0
		}

		for (int i = 0; i < n; i++) // O(N)
		{
			colours[v[i]].push_back(i + 1); // Store the index (1-based) of each plank in its respective color vector
		}

		for (int i = 1; i <= k; i++) // O(k)
		{
			colours[i].push_back(n + 1); // Append n+1 to each color vector
		}

		priority_queue<int> jumps[k + 1]; // Create a priority queue for each color to store jump lengths

		int ans = INT_MAX; // Initialize the answer to the maximum possible integer valucd

		for (int i = 1; i <= k; i++)
		{
			for (int j = 0; j < colours[i].size() - 1; j++)
			{
				// Calculate the jump length between consecutive planks of the same color
				jumps[i].push(colours[i][j + 1] - colours[i][j] - 1);
			} // x -> O(x log x)

			int max_val = jumps[i].top(); // Get the maximum jump length

			jumps[i].pop(); // Remove the maximum jump length from the queue

			// Split the maximum jump into two smaller jumps
			if (max_val % 2 == 0)
			{
				jumps[i].push(max_val / 2);
				jumps[i].push((max_val / 2) - 1);
			}
			else
			{
				jumps[i].push(max_val / 2);
				jumps[i].push(max_val / 2);
			}

			ans = min(ans, jumps[i].top()); // Update the answer with the smallest maximum jump
		} // O(N log N)

		cout << ans << "\n"; // Output the result for the current test case
	}

	return 0;
}