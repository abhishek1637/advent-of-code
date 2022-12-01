#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int findTopThreeNumber() {
    string arg;
    int sum = 0;
    vector<int> numbers;

    ifstream filestream("input.txt");

    if (filestream.is_open()) {
        while (getline(filestream, arg)) {
            if (arg.empty()) {
                numbers.push_back(sum);
                sum = 0;
                continue;
            }
            sum += stoi(arg);
        }
        numbers.push_back(sum);
    }

    filestream.close();
    partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end(), greater<int>());
    // solution for first part
    cout << numbers[0] << endl;
    return numbers[0] + numbers[1] + numbers[2];
}

int main() {
    cout << findTopThreeNumber() << endl;   
}