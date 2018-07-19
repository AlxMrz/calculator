
#include <iostream>
#include <sstream>
#include <map>
#include "App.h"
#include "UI.h"
using namespace std;

App::App(int argc, char **argv) :
leftOperand(""),
rightOperand(""),
action("") {
    this->argc = argc;
    this->argv = argv;
    this->ui = UI(this);
}

void App::run() {
    ui.startWindow();
    ui.createUI();
    ui.endWindow();
}



void App::makeCalc(bool isNewAction) {
    if (this->leftOperand != "" && this->rightOperand != "" && this->action != "" && isNewAction) {
        double endValue = 0;
        if (this->action == "+") {
            endValue = atof(this->leftOperand.c_str()) + atof(this->rightOperand.c_str());
            this->rightOperand = "";
        } else if (this->action == "-") {
            endValue = atof(this->leftOperand.c_str()) - atof(this->rightOperand.c_str());
            this->rightOperand = "";
        } else if (this->action == "/") {
            endValue = atof(this->leftOperand.c_str()) / atof(this->rightOperand.c_str());
            this->rightOperand = "";
        } else if (this->action == "*") {
            endValue = atof(this->leftOperand.c_str()) * atof(this->rightOperand.c_str());
            this->rightOperand = "";
        }
        this->action = "";
        ostringstream strs;
        strs << endValue;
        string str = strs.str();
        this->leftOperand = str;
    }
}

void App::prepareOutput(string& insertedValue, bool isNewAction) {
    if (this->action != "" && !isNewAction) {
        this->rightOperand += insertedValue;
    } else if (!isNewAction) {
        this->leftOperand += insertedValue;
    }
    if (isNewAction && this->rightOperand == "" && this->action != "" && insertedValue != "=") {
        this->action = insertedValue;
    }
}



bool App::isNewAction(string action) {
    if (action == "=") {
        return true;
    }
    if (action == "+" ||
            action == "-" ||
            action == "/" ||
            action == "*"

            ) {
        if (this->action == "") {
            this->action = action;

        }
        return true;
    }
    return false;
}


