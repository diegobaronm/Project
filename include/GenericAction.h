/// This class implements a polymorphic action class that is used to execute the evetns in the menus.
#ifndef GENERIC_ACTION_H
#define GENERIC_ACTION_H

#include <iostream>
#include "AppContext.h"
#include "Menu.h"

/// Abstract class
class GenericAction {
public:
    GenericAction() = default;
    GenericAction(const GenericAction&) = delete;
    GenericAction& operator=(const GenericAction&) = delete;
    GenericAction&& operator=(GenericAction&&) = delete;
    virtual ~GenericAction() = default;
    virtual void execute(AppContext& appContext, const std::vector<Menu>& menus) = 0;
};

/// These classes implement atomic actions.

class HelloWorld : public GenericAction {
public:
    HelloWorld() = default;
    virtual ~HelloWorld() = default;
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        std::cout << "Hello World!" << std::endl;
    }
};

class QuitApp : public GenericAction {
public:
    QuitApp() = default;
    virtual ~QuitApp() = default;
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        appContext.quitApp();
    }
};

class GoBack : public GenericAction {
public:
    GoBack() = default;
    virtual ~GoBack() = default;
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        int currentMenuId = appContext.getCurrentMenuId();
        int previousMenuId = appContext.getPreviousMenuId();
        // Set the current menu id to the previous one.
        appContext.setCurrentMenuId(previousMenuId);
        // Set the previous menu id to the current one.
        appContext.setPreviousMenuId(currentMenuId);
    }
};

class ChangeMenu : public GenericAction {
public:
    ChangeMenu() = default;
    virtual ~ChangeMenu() = default;
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        int currentMenuId = appContext.getCurrentMenuId();
        int previousMenuId = appContext.getPreviousMenuId();
        // Set the previous menu id to the current one.
        appContext.setPreviousMenuId(currentMenuId);
        // Get the selected menu item and the name of the item.
        int selectedMenuItem = appContext.getSelectedMenuItem();
        const Menu& currentMenu = menus[currentMenuId];
        std::vector<std::string> menuItems = currentMenu.getItems();
        std::string itemName = menuItems[appContext.getSelectedMenuItem()-1];
        // Get the ID of the menu called as the just retreived item name.
        for (const auto menu : menus){
            if (menu.getTitle() == itemName){
                appContext.setCurrentMenuId(menu.getId());
                break;
            }
        }
    }
};

#endif 