/// Main file for the program.

#include "Menu.h"
#include "AppContext.h"
#include "App.h"

#include <iostream>

int main() {
    std::cout<<"Hello World!"<<std::endl;
    std::vector<std::string> menuItems1{"Item 1", "Menu 2", "Item 3"};
    std::vector<std::string> menuItems2{"Item 1"};
    Menu menu1(menuItems1,"Menu 1",true,false);
    Menu menu2(menuItems2,"Menu 2",true,true);
    
    std::vector<Menu> menus{menu1,menu2};

    AppContext appContext(0);
    App app(appContext,menus);
    app.run();

}