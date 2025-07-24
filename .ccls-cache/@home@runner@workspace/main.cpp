#include <iostream>
using namespace std;

// Function to get a valid score between 0 and 10
double getScore() {
    double score;
    cout << "Enter judge's score (0 - 10): ";
    cin >> score;
    while (score < 0.0 || score > 10.0) {
        cout << "Invalid score. Please enter a score between 0 and 10: ";
        cin >> score;
    }
    return score;
}

// Returns true if first value is less than second
bool isLower(double a, double b) {
    return a < b;
}

// Returns true if first value is greater than second
bool isHigher(double a, double b) {
    return a > b;
}

// Calculates average score after removing min and max
double calcAverage(double total, double minScore, double maxScore) {
    return (total - minScore - maxScore) / 3.0;
}

int main() {
    double score, total = 0.0, minScore, maxScore;

    // First score
    score = getScore();
    total = score;
    minScore = score;
    maxScore = score;

    // Next 4 scores
    for (int i = 1; i < 5; i++) {
        score = getScore();
        total += score;
        if (isLower(score, minScore)) minScore = score;
        if (isHigher(score, maxScore)) maxScore = score;
    }

    double average = calcAverage(total, minScore, maxScore);
    cout << "Final average score: " << average << endl;

    return 0;
}
