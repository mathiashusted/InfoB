#include <iostream>
#include <vector>
#include <utility>

std::vector<std::pair<int,int>> paare (std::vector<int> a, std::vector<int> b) {
    std::vector<std::pair<int,int>> output;
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++) {
            output.push_back(std::make_pair(a[i],b[j]));
        }
    }
    return output;
}


int main() {
    std::vector<int> a = {1,2,3};
    std::vector<int> b = {4,5};
    std::vector<std::pair<int,int>> output = paare(a,b);
    for (size_t i = 0; i < output.size(); i++) {
        std::cout << "{" << output[i].first << ", " << output[i].second << "}" << std::endl;
    }
}