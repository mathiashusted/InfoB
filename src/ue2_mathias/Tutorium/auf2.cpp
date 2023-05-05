#include <iostream>
#include <string>

using namespace std;

enum class Menu {
    Vorspeise,
    Hauptgang,
    Dessert
};

struct Menupunkt {
    Menu menu;
    string name;
    string description;
    float price;
};

int main() {
    Menupunkt vorspeise = {Menu::Vorspeise, "Vorspeise", "Speist vor", 9.0};
    Menupunkt hauptgang = {Menu::Hauptgang, "Hauptgang", "Schmeckt lecker", 15.4};
    
}