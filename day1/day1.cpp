#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int* loadMass();
int getFuelCost(int fuel);

int main() {
    int* masses = loadMass();
    unsigned int sum = 0;
    unsigned int secondPartSum = 0;
    for(int i = 0; i < 100; i++) {
        sum += masses[i] / 3 - 2;
        secondPartSum += getFuelCost(masses[i]);
    }
    cout << "The sum is: " << sum << endl;
    cout << "Total cost is:: " << secondPartSum << endl;
    return 0;
}

int* loadMass() {
    static int masses[100];
    ifstream file;
    file.open(R"(U:\CLionProjects\Advent2019\day1\input.txt)");
    if(!file) {
        cout << "Unable to open the input file.";
        exit(1);
    }
    string line;
    int counter = 0;
    while(getline(file, line)) {
        masses[counter] = stoi(line);
        cout << line << endl;
        counter++;
    }
    file.close();
    return masses;
}

int getFuelCost(int fuel) {
    static int fuelSum;
    int fuelCost = fuel / 3 - 2;
    if(fuelCost <= 0) {
        int temp = fuelSum;
        fuelSum = 0;
        return temp;
    }
    fuelSum += fuelCost;
    getFuelCost(fuelCost);
}