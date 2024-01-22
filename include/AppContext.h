/// AppContext class: This class is used to store the application status.

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

class AppContext {
    public:
    // Start the app giving it the id of the start menu, set the previous one to the same at the beginning.
    AppContext(int startMenuId): m_currentMenuId(startMenuId), m_previousMenuId(startMenuId) {};
    
    // Getters.
    int getCurrentMenuId() const {return m_currentMenuId;}
    int getPreviousMenuId() const {return m_previousMenuId;}
    bool isRunning() const {return m_isRunning;}
    int getSelectedMenuItem() const {return m_selectedMenuItem;}

    // Setters.
    void setCurrentMenuId(int currentMenuId) {m_currentMenuId = currentMenuId;}
    void setPreviousMenuId(int previousMenuId) {m_previousMenuId = previousMenuId;}
    void quitApp() {m_isRunning = false;}
    void setSelectedMenuItem(int selectedMenuItem) {m_selectedMenuItem = selectedMenuItem;}

    private:
    int m_currentMenuId{};
    int m_previousMenuId{};
    bool m_isRunning{true};
    int m_selectedMenuItem{0};
};

#endif