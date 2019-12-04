#include <iostream>

using namespace std;

void part2();

void part1();

int digit1 = 128392;
int digit2 = 643281;

int main() {
    part1();
    part2();
    return 0;
}

void part1() {
    int finalCount = 0;
    for (int i = digit1; i < digit2; i++) {
        int digits[5];
        int counter = 0;
        int w = i;
        bool doubleFound = false;
        do {
            int digit = w % 10;
            w /= 10;
            digits[counter] = digit;
            counter++;
        } while (w > 0);
        for (int k = 0; k < 5; k++) {
            if (k + 1 != 6) {
                if (digits[k] == digits[k + 1]) {
                    doubleFound = true;
                }
            }
            if (digits[k] < digits[k + 1]) {
                doubleFound = false;
                break;
            }
        }
        if (doubleFound) {
            finalCount++;
        }
    }
    cout << "Total Count: " << finalCount << endl;
}

void part2() {
    int finalCount = 0;
    for (int i = digit1; i < digit2; i++) {
        int digits[5];
        int counter = 0;
        int w = i;
        bool doubleFound = false;
        int numberOfDoubles = 0;
        int numberOfTriples = 0;
        int lastTripleDigit = -10;
        do {
            int digit = w % 10;
            w /= 10;
            digits[counter] = digit;
            counter++;
        } while (w > 0);
        for (int k = 0; k < 5; k++) {
            if (digits[k] == digits[k + 1] && digits[k] != lastTripleDigit) {
                if (digits[k] == digits[k + 1] && digits[k] == digits[k + 2]) {
                    numberOfTriples++;
                    lastTripleDigit = digits[k];
                } else {
                    numberOfDoubles++;
                }
                doubleFound = true;
            } else if (digits[k] < digits[k + 1]) {
                doubleFound = false;
                break;
            }
        }
        if (doubleFound) {
            if (numberOfDoubles >= 1 && numberOfTriples <= 1) {
                finalCount++;
            }
        }
    }
    cout << "Total Count Part 2: " << finalCount << endl;
}