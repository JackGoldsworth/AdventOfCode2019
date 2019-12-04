#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int *loadOpCodes();

void part1();

void part2();

int main() {
    part1();
    part2();
    return 0;
}

void part1() {
    int *opCodes = loadOpCodes();
    for (int i = 0; i < 200; i += 4) {
        cout << "Position " << i << ": " << opCodes[i] << endl;
        int place = opCodes[i + 3];
        int add1 = opCodes[i + 1];
        int add2 = opCodes[i + 2];
        if (opCodes[i] == 1) {
            opCodes[place] = opCodes[add1] + opCodes[add2];
        } else if (opCodes[i] == 2) {
            opCodes[place] = opCodes[add1] * opCodes[add2];
        } else if (opCodes[i] == 99) {
            cout << "Position 0: " << opCodes[0] << endl;
            return;
        }
    }
}

void part2() {
    for (int x = 0; x <= 99; x++) {
        for (int y = 0; y <= 99; y++) {
            int *opCodes = loadOpCodes();
            cout << "X: " << x << " Y: " << y << endl;
            for (int i = 0; i < 200; i += 4) {
                if (i == 0) {
                    opCodes[1] = x;
                    opCodes[2] = y;
                }
                int place = opCodes[i + 3];
                int add1 = opCodes[i + 1];
                int add2 = opCodes[i + 2];
                if (opCodes[i] == 1) {
                    opCodes[place] = opCodes[add1] + opCodes[add2];
                } else if (opCodes[i] == 2) {
                    opCodes[place] = opCodes[add1] * opCodes[add2];
                } else if (opCodes[i] == 99) {
                    if (opCodes[0] == 19690720) {
                        cout << "Position 0: " << 100 * x + y << endl;
                        exit(0);
                    }
                }
            }
        }
    }
}

int *loadOpCodes() {
    static int opCodes[200];
    ifstream file;
    file.open(R"(U:\CLionProjects\Advent2019\day2\input.txt)");
    if (!file) {
        cout << "Unable to open the input file.";
        exit(1);
    }
    string line;
    int counter = 0;
    while (getline(file, line, ',')) {
        opCodes[counter] = stoi(line);
        counter++;
    }
    file.close();
    return opCodes;
}