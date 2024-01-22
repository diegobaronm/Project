/// Menu class: This class is used to create a menu and display it on the screen.
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

class Menu {
    public:
    Menu(const std::vector<std::string>& menuItems,const std::string& title,bool includeQuit = false, bool includeGoBack = false);
    void printMenu() const;
    std::vector<std::string> getItems() const {return m_menuItems;}
    std::string getTitle() const {return m_title;}
    int getId() const {return m_menuId;}

    private:
    const int m_menuId; // This variable is used to store the menu id of the current menu.
    static std::vector<int> s_menuIds; // This vector is used to store the menu ids of all the menus created.
    std::vector<std::string> m_menuItems; // This vector is used to store the menu items of the current menu.
    const std::string m_title;
};

#endif