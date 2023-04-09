// Algorithm: Reservoir sampling and K == 1
// https://en.wikipedia.org/wiki/Reservoir_sampling
// "Reservoir sampling is a family of randomized algorithms for randomly choosing a sample of k items from a list S containing n items, where n is either a very large or unknown number. 
// Typically n is large enough that the list doesn't fit into main memory."
// This algorithm very fit for random selection in streaming data.
// Proof: The probability of N-th element is 1/N, and the rest (1 - 1 / N) = (N - 1) / N will be shared equally by previous N - 1. So (N-1)/N/(N-1) = 1/N

#include <bits/stdc++.h>
#include <time.h>

std::string random_line(std::ifstream& file) {
    srand(time(NULL));  // this line make sure rand() function returns different random number for each call
    std::string line, picked_line;
    int i=1;  // Initialize value with first line
    while (std::getline(file, line)) {
        if ((rand() % i)==0) {   // Random range from 0 to i-1
            picked_line = line; //replace picked_line with i-th line with probability 1/i
        }
        i++;
    }
    return picked_line;
}

int main(int argc, char* argv[]) {
    std::ifstream inFile;
    inFile.open(argv[1]);
    std::string outLine = random_line(inFile);
    inFile.close();
    std::cout << outLine << std::endl;
    return 0;
}

// Time Complexity: O(N) where N is number line in the input text file.
// Space Complexity: O(M) where M is size of line longest in the input text file.