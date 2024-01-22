/// File that contains a dictionar of actions and menus that contain them.
#include<map>
#include<vector>
#include<memory>
#include<string>

#include"GenericAction.h"

typedef std::vector<std::shared_ptr<GenericAction>> actionsVector; // This type is used to store a vector of actions.

// Create the actions.
const std::shared_ptr<GenericAction> g_helloWorld = std::make_shared<HelloWorld>();
const std::shared_ptr<GenericAction> g_quitApp = std::make_shared<QuitApp>();
const std::shared_ptr<GenericAction> g_goBack = std::make_shared<GoBack>();
const std::shared_ptr<GenericAction> g_changeMenu = std::make_shared<ChangeMenu>();

// Create the vector of functions for the menus.
// IMPORTANT: The order of the actions matters - it must match the order of the menu items.

const actionsVector g_actionsMenu1{g_helloWorld,g_changeMenu,g_helloWorld,g_quitApp};
const actionsVector g_actionsMenu2{g_helloWorld,g_goBack,g_quitApp};

// Create the dictionary of actions. Assign to each menu title a vector of actions.
extern const std::map<std::string,actionsVector> g_actionsDictionary{
    {"Menu 1",g_actionsMenu1},
    {"Menu 2",g_actionsMenu2}
};