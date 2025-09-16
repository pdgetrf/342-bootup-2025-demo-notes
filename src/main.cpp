#include <iostream>
#include <vector>

void extractDigits(int n, std::vector<int>& result) {
    const int TEN_FOR_DIGIT = 10;
    if (n == 0) return;
    extractDigits(n / TEN_FOR_DIGIT, result); // recursion goes left to right
    result.push_back(n % TEN_FOR_DIGIT);      // take last digit
}

struct TestCase {
    int input;
    std::vector<int> expected;
};

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
        {8888,   {8,8,8,8}},
        {1002, {1, 0, 0, 2}}
    };

    for (size_t i = 0; i < tests.size(); i++) {
        testExtractDigits(tests[i]);
    }
    return 0;
}

