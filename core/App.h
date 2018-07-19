#ifndef APP_H
#define APP_H
#include <map>
#include <string>
#include "UI.h"
#include "Calculator.h"
using namespace std;

class App {
public:
    int argc;
    char **argv;
    UI ui;
    Calculator calc;
    
    App(int argc, char **argv);
    void run();
private:
    void createUI();
};
#endif /* APP_H */

