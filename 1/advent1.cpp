#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/* Solution for first part */
int findTopNumber() {
    string arg;
    int sum = 0, max = -1;

    ifstream filestream("input.txt");

    if (filestream.is_open()) {
        while (getline(filestream, arg)) {
            if (arg.empty()) {
                if (max < sum)
                    max = sum; 
                sum = 0;
                continue;
            }
            sum += stoi(arg);
        }
    }
    filestream.close();

    return (max < sum) ? sum : max ;
}

/* solution for second part */
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
    return numbers[0] + numbers[1] + numbers[2];
}

int main() {
    cout << findTopNumber() << endl; 
    cout << findTopThreeNumber() << endl;   
}