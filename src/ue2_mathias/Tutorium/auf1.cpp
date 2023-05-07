#include <iostream>
#include <vector>

using namespace std;

vector<int> rev(vector<int> input) {
    vector<int> output;
    for (int i = static_cast<int>(input.size() -1); i >= 0; i--) {
        output.push_back(input[i]);
    }
    return output;
}

int main() {
    vector<int> inp = {1, 3, 5, 7, 9};
    vector<int> out = rev(inp);
    for (size_t i = 0; i < out.size(); i++) {
        cout << out[i] << endl;
    }
}