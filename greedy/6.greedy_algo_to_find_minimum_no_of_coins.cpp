class Solution{
public:
    // Function to find the minimum partition of a given value N using a set of coins
    std::vector<int> minPartition(int N) {
        // Array of coin denominations in descending order
        std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

        // Size of the coins array
        int size = 10;
        
        // Index variable starting from the last coin denomination
        int i = size - 1;

        // Vector to store the result (selected coins for the minimum partition)
        std::vector<int> ans;

        // Iterate through the coin denominations
        while (N > 0 && i >= 0) {
            // Check if the current coin denomination is greater than the remaining value N
            if (N < coins[i]) {
                // If yes, move to the next smaller coin denomination
                i--;
            } else {
                // If no, subtract the coin value from N and add the coin to the result
                N = N - coins[i];
                ans.push_back(coins[i]);
            }
        }

        // Return the vector containing the minimum partition of N
        return ans;
    }
};