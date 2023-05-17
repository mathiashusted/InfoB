#include <iostream>
#include <vector>

int fibonacci(unsigned n) {
    unsigned sum = 0;
    std::vector<unsigned> count;
    count.push_back(0);
    count.push_back(1);
    for (unsigned i = 2; i < n; i++) {
        sum = count[i-2] + count[i-1];
        count.push_back(sum);
    }
    return sum;
}

int main() {
    unsigned n;
    std::cin >> n;
    n+=1;
    std::cout << (n+1) << "-te Fibonacci Zahl: " << fibonacci(n) << std::endl;
}