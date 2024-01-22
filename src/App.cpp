#include<map>
#include "App.h"
#include "GenericAction.h"
#include "Menu.h"
#include "Debug.h"

typedef std::vector<std::shared_ptr<GenericAction>> actionsVector; 

extern const std::map<std::string,actionsVector> g_actionsDictionary;

void App::setup(){
    // Check the size of the menu items vector is the same as the size of the actions vector for that menu.
    for(auto menu : m_appMenus){
        DEBUG_LOG("Checking menu " << menu.getTitle());
        if(menu.getItems().size() != g_actionsDictionary.at(menu.getTitle()).size()){
            std::cout << "Error: The number of menu items for menu " << menu.getTitle() << " does not match the number of actions for that menu." << std::endl;
        }
    }
}

void App::run() {
    //Run the application.
    while (m_appContext.isRunning()){
        // Get the current and previous menu ids.
        int currentMenuId = m_appContext.getCurrentMenuId();
        int previousMenuId = m_appContext.getPreviousMenuId();
        // Print the current menu.
        const Menu& currentMenu = m_appMenus[currentMenuId];
        currentMenu.printMenu();
        // Get the selected menu item.
        int selectedMenuItem;
        std::cin >> selectedMenuItem;
        m_appContext.setSelectedMenuItem(selectedMenuItem);
        selectedMenuItem = m_appContext.getSelectedMenuItem();
        std::cout << "You selected: " << selectedMenuItem <<std::endl;
        // Get the corrected function pointer and execute the corresponding action.
        g_actionsDictionary.at(currentMenu.getTitle())[selectedMenuItem-1]->execute(m_appContext,m_appMenus);
        
        
    }
}
