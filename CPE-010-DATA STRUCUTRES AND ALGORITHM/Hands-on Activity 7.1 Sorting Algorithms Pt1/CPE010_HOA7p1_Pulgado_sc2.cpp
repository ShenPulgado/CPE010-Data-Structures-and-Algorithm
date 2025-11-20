#include <iostream>
#include <cstdlib>
#include <ctime>
#include "voting.h"
using namespace std;

int main() {
    const int SIZE = 100;         
    const int CANDIDATES = 5;     
    int votes[SIZE];

    for (int i = 0; i < SIZE; i++) {
        votes[i] = rand() % CANDIDATES + 1;
    }

    cout << "Unsorted Votes:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << votes[i] << " ";
    }
    cout << "\n\n";

    bubbleSort(votes, SIZE);

    cout << "Sorted Votes:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << votes[i] << " ";
    }
    cout << "\n\n";

    int counts[CANDIDATES];
    countVotes(votes, SIZE, counts, CANDIDATES);

    cout << "Vote Counts (Result of the Algorithm):\n";
    for (int i = 0; i < CANDIDATES; i++) {
        cout << "Candidate " << (i + 1) << ": " << counts[i] << " votes\n";
    }
    cout << "\n";

    int winner = findWinner(counts, CANDIDATES);
    cout << "Winner: Candidate " << (winner + 1) << "\n";

    return 0;
}

