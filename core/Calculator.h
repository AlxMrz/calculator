#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>

class App;
class Calculator 
{
public:
    Calculator(App* app);
    Calculator();
    App* app;
    std::string leftOperand= "";
    std::string action= "";
    std::string rightOperand= "";
    void makeCalc(bool isNewValue);
    bool isNewAction(std::string action);
};


#endif /* CALCULATOR_H */

