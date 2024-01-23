#include <iostream>
#include "Menu.h"

std::vector<int> Menu::s_menuIds(0); // Initialising the static vector.

// Initialise the menu members and add a new menu id to the static vector. Also check if the go back and quit menu items are to be included.
Menu::Menu(const std::vector<std::string>& menuItems,const std::string& title ,bool includeQuit, bool includeGoBack) :
    m_menuItems(menuItems),
    m_title(title),
    m_menuId(static_cast<int>(Menu::s_menuIds.size())) // The menu id is the size of the vector.
{
    // Add one menu Id each time one is created.
    Menu::s_menuIds.push_back(m_menuId);
    // Add the optional go back and quit menu items.
    if(includeGoBack) m_menuItems.push_back("Go Back");
    if(includeQuit) m_menuItems.push_back("Quit");
}


// Print the menu in a nice format. First the title, then the menu items. 
void Menu::printMenu() const {
    std::cout << m_title << std::endl;
    for(int i = 0; i < m_menuItems.size(); ++i) {
        std::cout << (i+1) << ")" << m_menuItems[i] << std::endl;
    }
}
