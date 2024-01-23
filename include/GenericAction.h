/// This class implements a polymorphic action class that is used to execute the evetns in the menus.
#ifndef GENERIC_ACTION_H
#define GENERIC_ACTION_H

#include <iostream>
#include <string>
#include "AppContext.h"
#include "Menu.h"

/// Abstract class to create the interface for the different actions.
class GenericAction {
public:
    GenericAction() = default;
    GenericAction(const GenericAction&) = delete;
    GenericAction& operator=(const GenericAction&) = delete;
    GenericAction&& operator=(GenericAction&&) = delete;
    virtual ~GenericAction() = default;
    virtual void execute(AppContext& appContext, const std::vector<Menu>& menus) = 0;
    virtual std::string getActionName() const = 0; // This function returns the name (can be used as type) of the action.
};

/// These classes implement atomic actions.
// Just print "Hello World!".
class HelloWorld : public GenericAction {
public:
    HelloWorld() = default;
    virtual ~HelloWorld() = default;
    std::string getActionName() const override{ return "HelloWorld";}
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        std::cout << "Hello World!" << std::endl;
    }
};
// Quit the application in the next iteration of the main loop. 
// TO DO: This is where any cleaning should be done?
class QuitApp : public GenericAction {
public:
    QuitApp() = default;
    virtual ~QuitApp() = default;
    std::string getActionName() const override{ return "QuitApp";}
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        appContext.quitApp();
    }
};

// Goes back to the previous menu.
class GoBack : public GenericAction {
public:
    GoBack() = default;
    virtual ~GoBack() = default;
    std::string getActionName() const override{ return "GoBack";}
    void execute(AppContext& appContext, const std::vector<Menu>& menus) override {
        int currentMenuId = appContext.getCurrentMenuId();
        int previousMenuId = appContext.getPreviousMenuId();
        // Set the current menu id to the previous one.
        appContext.setCurrentMenuId(previousMenuId);
        // Set the previous menu id to the current one.
        appContext.setPreviousMenuId(currentMenuId);
    }
};

// Changes the current menu to the one selected by the user.
class ChangeMenu : public GenericAction {
public:
    ChangeMenu() = default;
    virtual ~ChangeMenu() = default;
    std::string getActionName() const override{ return "ChangeMenu";}
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
        // Get the ID of the menu called as the retreived item name.
        for (const auto menu : menus){
            if (menu.getTitle() == itemName){
                appContext.setCurrentMenuId(menu.getId());
                break;
            }
        }
    }
};

#endif 