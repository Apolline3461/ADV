#include <iostream>
#include <vector>
#include <cmath>

int sumArray(const std::vector<int>& arr) {
    int sum = 0;
    int size = arr.size();
    int i = 0;

    for (; i + 3 < size; i+=4)
        sum += arr[i] + arr[i+1] + arr[i+2] + arr[i+3];
    for (; i < size; i++)
        sum += arr[i];
    return sum;
}

void exo1() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "Sum: " << sumArray(arr) << std::endl;
}

std::string concatenateStrings(const std::vector<std::string>&
strings) {
    std::string result;
    int totalLength = 0;

    for (auto &str : strings)
        totalLength += str.size();
    result.reserve(totalLength);
    for (const auto& str : strings) {
        result += str;
    }
    return result;
}

void exo2() {
    std::vector<std::string> strings = {"Hello", " ", "World", "!"};
    std::cout << concatenateStrings(strings) << std::endl;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int sqrtN = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= sqrtN; i+=2) {
        if (n % i == 0) return false;
    }
    return true;
}

void exo3() {
    int num = 28;
    std::cout << num << " is " << (isPrime(num) ? "prime" : "not prime" ) << std::endl;
}

void transposeMatrix(const std::vector<std::vector<int>>& matrix,
                     std::vector<std::vector<int>>& transposed) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (transposed.size() != cols || transposed[0].size() != rows)
        transposed.assign(cols, std::vector<int>(rows));

    for (int i = 0; i < rows; i++) {
        const auto&row = matrix[i];
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = row[j];
        }
    }
}
void exo4() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3},
                                            {4, 5, 6}};
    std::vector<std::vector<int>> transposed;
    transposeMatrix(matrix, transposed);
    for (const auto &row: transposed) {
        for (const auto &elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    exo1();
    exo2();
    exo3();
    exo4();
    return 0;
}
