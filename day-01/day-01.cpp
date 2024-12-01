#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>


int part1(std::vector<int> &left, std::vector<int> &right) {
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    int res = 0;
    for (int i = 0; i < left.size(); i++) {
        res += std::abs(left[i] - right[i]);
    }
    return res;
}


int part2(std::vector<int> &left, std::vector<int> &right) {
    std::map<int, int> rightMap;
    for (int i = 0; i < right.size(); i++) {
        rightMap[right[i]]++;
    }
    int res = 0;
    for (int i = 0; i < left.size(); i++) {
        res += std::abs(left[i]  * rightMap[left[i]]);
    }
    return res;
}


int main() {
    std::ifstream inputFile("/Users/khavlaren/projects/advent-of-code-2024/day-01/input.txt");
    std::vector<int> firstNumbers;
    std::vector<int> secondNumbers;
    std::string line;

    if (inputFile.is_open()) {
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            int first, second;
            if (iss >> first >> second) {
                firstNumbers.push_back(first);
                secondNumbers.push_back(second);
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::cout << "Part 1: " << part1(firstNumbers, secondNumbers) << std::endl;
    std::cout << "Part 2: " << part2(firstNumbers, secondNumbers) << std::endl;
    return 0;
}