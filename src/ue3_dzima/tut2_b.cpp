//
// Created by gromdimon on 05.05.23.
//

#include <iostream>
// Erstelle ein Programm, das ein Restaurantmenü darstellt. Verwende dazu ein Enum, das die verschiedenen Menüpunkte auflistet (Vorspeise, Hauptgang, Dessert) und ein Struct, das die Details zu jedem Menüpunkt enthält (Name, Beschreibung und Preis). Das Programm soll dem Benutzer ermöglichen, das Menü anzuzeigen und nach einem bestimmten Menüpunkt zu suchen.
// Hinweis: Verwende std::string für die Namen und Beschreibungen und float für die Preise.

enum class Menu {
  Vorspeise,
  Hauptgang,
  Dessert
};

struct MenuDetails {
  Menu menu;
  std::string name;
  std::string description;
  float price;
};

void print_menu(MenuDetails menu) {
  std::cout << "Menu: " << static_cast<int>(menu.menu) << std::endl;
  std::cout << "Name: " << menu.name << std::endl;
  std::cout << "Description: " << menu.description << std::endl;
  std::cout << "Price: " << menu.price << std::endl;
}

int main() {
  MenuDetails vorspeise = {Menu::Vorspeise, "Vorspeise", "Vorspeise", 1.0};
  MenuDetails hauptgang = {Menu::Hauptgang, "Hauptgang", "Hauptgang", 2.0};
  MenuDetails dessert = {Menu::Dessert, "Dessert", "Dessert", 3.0};
  MenuDetails menu[] = {vorspeise, hauptgang, dessert};
  int menu_size = sizeof(menu) / sizeof(menu[0]);
  for (int i = 0; i < menu_size; i++) {
    print_menu(menu[i]);
  }
  return 0;
}