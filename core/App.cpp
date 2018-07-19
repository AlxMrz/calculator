#include <iostream>
#include <sstream>
#include <map>
#include "App.h"
#include "UI.h"
#include "Calculator.h"
using namespace std;

App::App(int argc, char **argv)
{
    this->argc = argc;
    this->argv = argv;
    this->ui = UI(this);
    this->calc = Calculator(this);
}

void App::run() {
    ui.startWindow();
    ui.createUI();
    ui.endWindow();
}

void App::prepareOutput(string& insertedValue, bool isNewAction) {
    if (this->calc.action != "" && !isNewAction) {
        this->calc.rightOperand += insertedValue;
    } else if (!isNewAction) {
        this->calc.leftOperand += insertedValue;
    }
    if (calc.isNewAction(insertedValue) && this->calc.rightOperand == "" && this->calc.action != "" && insertedValue != "=") {
        this->calc.action = insertedValue;
    }
}






