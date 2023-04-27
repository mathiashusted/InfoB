#include <iostream>

using namespace std;

int number_digits(long input) {
    int digits = 0;
    long inp = input;
    while (inp/10) {
        digits++;
        inp /= 10;
    }
    return (digits+1);
}

long quersumme(long input) {
    int length = number_digits(input);
    long sum = 0;
    for (int i = input; i < number_digits; i++) {
        sum += input[i];
    }
} 

int main() {
    cout << number_digits(2233) << endl;
}