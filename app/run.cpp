/// Main file for the program.

#include "Menu.h"
#include "AppContext.h"
#include "App.h"

#include <iostream>

extern const std::vector<Menu> g_menus;

int main() {
    std::cout<<"Hello World!"<<std::endl;

    AppContext appContext(0);
    App app(appContext,g_menus);
    app.run();
}