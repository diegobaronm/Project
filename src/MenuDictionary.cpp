///  This file contains all the Menu object definitions.
#include<vector>
#include<string>
#include"Menu.h"

std::vector<std::string> menuItems1{"Item 1", "Menu 2", "Item 3"};
std::vector<std::string> menuItems2{"Item 1"};

Menu menu1(menuItems1,"Menu 1",true,false);
Menu menu2(menuItems2,"Menu 2",true,true);

// Expose this in the other translation units.
extern const std::vector<Menu> g_menus{menu1,menu2};