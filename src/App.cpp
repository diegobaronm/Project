#include<map>
#include "App.h"
#include "GenericAction.h"
#include "Menu.h"
#include "Debug.h"

typedef std::vector<std::shared_ptr<GenericAction>> actionsVector; 

extern const std::map<std::string,actionsVector> g_actionsDictionary;

// This function performs various checks on the application creation.
// 1) Check that the number of menu items for each menu is the same as the number of actions for that menu.
// 2) Check that the menu names are unique.
// 3) Check that the actions that perform a menu changed are correctly located and reference an existing menu.

void App::setup(){
    // Check the size of the menu items vector is the same as the size of the actions vector for that menu.
    for(auto menu : m_appMenus){
        DEBUG_LOG("Checking menu " << menu.getTitle());
        if(menu.getItems().size() != g_actionsDictionary.at(menu.getTitle()).size()){
            std::cout << "Error: The number of menu items for menu " << menu.getTitle() << " does not match the number of actions for that menu." << std::endl;
        }
    }
    // Check that the menus containing ChangeMenuAction fulfill two conditions:
    // 1. The items vector for that menu contains at least one item with the name of another menu.
    // 2. The position of the item that refereces another menu has the correct position to the ChangeMenuAction.

    // Store the menu titles in a vector, all menus should have a unique name.
    std::vector<std::string> menuTitles;
    for(auto menu : m_appMenus){
        // Check if the menu title is already in the vector.
        if(std::find(menuTitles.begin(),menuTitles.end(),menu.getTitle()) != menuTitles.end()){
            DEBUG_LOG("Error: The menu " << menu.getTitle() << " is duplicated.");
            exit(1);
        } else{
            // Add the menu title to the vector.
            menuTitles.push_back(menu.getTitle());
        }
    }
    // Iterate the actions dictionary looking for ChangeMenuActions.
    for(const auto& menuActionsPair : g_actionsDictionary){
        // Iterate the actions vector for each menu.
        size_t index{};
        for(const auto& action : menuActionsPair.second){
            // Check if the action is a ChangeMenuAction.
            DEBUG_LOG("Checking action " << action->getActionName());
            if(action->getActionName() == "ChangeMenu"){
                // Loop through the menu object to find the items that have the same index as the ChangeMenuAction.
                std::cout << "Index = " << index << std::endl;
                for(const auto& menu : m_appMenus){
                    if (menu.getTitle() == menuActionsPair.first){
                        const std::vector<std::string>& menuItems = menu.getItems();
                        const std::string& itemName = menuItems[index];
                        // Check if the item name is the same as the name of another menu.
                        if(std::find(menuTitles.begin(),menuTitles.end(),itemName) == menuTitles.end()){
                            DEBUG_LOG("Error: The menu = " << menu.getTitle() << " contains an item called = " << itemName << "." <<std::endl 
                            << "at position " << index+1 << " in the items vector."
                            "However, this name is not the name of another menu.");
                            exit(1);
                        }
                    }
                }
            }
            index++; // Check the next action.
        }
    }
}

// This function runs the application.

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
        std::cout << std::endl; // For spacing.   
    }
}
