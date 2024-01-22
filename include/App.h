/// App class: this class acts as the manager for the application.
#ifndef APP_H
#define APP_H
#include <vector>

#include "Menu.h"
#include "AppContext.h"

class App{
    public:
    App(const AppContext& appContext, const std::vector<Menu>& appMenus): m_appContext(appContext), m_appMenus(appMenus) {
        // First, setup the application.
        std::cout << "Setting up the application..." << std::endl;
        setup();
    };
    void setup();
    void run();


    private:
    AppContext m_appContext;
    const std::vector<Menu> m_appMenus;


};


#endif