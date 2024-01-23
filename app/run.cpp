/// Main file for the program.

#include "Menu.h"
#include "AppContext.h"
#include "App.h"

#include <iostream>

extern const std::vector<Menu> g_menus;

int main() {
    App app(AppContext(0),g_menus);
    app.run();
}