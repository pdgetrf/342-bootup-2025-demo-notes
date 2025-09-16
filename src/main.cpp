#include <iostream>
#include <vector>

// Recursively extract digits of n and store in result
void extractDigits(int n, std::vector<int>& result) {
    if (n == 0) return;
    extractDigits(n / 10, result); // recursion goes left to right
    result.push_back(n % 10);      // take last digit
}

// Define test case structure
struct TestCase {
    int input;
    std::vector<int> expected;
};

// Function to run a single test
void testExtractDigits(const TestCase& t) {
    std::vector<int> result;
    extractDigits(t.input, result);

    if (result == t.expected) {
        std::cout << "PASS: input=" << t.input << std::endl;
    } else {
        std::cout << "FAIL: input=" << t.input << std::endl;
        std::cout << "Expected: ";
        for (int d : t.expected) std::cout << d << " ";
        std::cout << "\nGot: ";
        for (int d : result) std::cout << d << " ";
        std::cout << "\n";
    }
}

int main() {
    std::vector<TestCase> tests = {
        {123, {1, 2, 3}},
        {405, {4, 0, 5}},
        {7,   {7}},
        {1002, {1, 0, 0, 2}}
    };

    for (size_t i = 0; i < tests.size(); i++) {
        testExtractDigits(tests[i]);
    }
    return 0;
}

