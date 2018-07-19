#ifndef APP_H
#define APP_H
#include <map>
#include <string>
#include "UI.h"
using namespace std;

class App {
public:
  
    string leftOperand= "";
    string action= "";
    string rightOperand= "";
    int argc;
    char **argv;
    UI ui;

    App(int argc, char **argv);
    void run();
    

    void makeCalc(bool isNewValue);
    void prepareOutput(string& insertedValue, bool isNewAction);
    bool isNewAction(string action);

    
private:

    void createUI();
    
    
};

#endif /* APP_H */

