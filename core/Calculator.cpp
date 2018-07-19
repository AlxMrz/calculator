#include <iostream>
#include <sstream>
#include "Calculator.h"

using namespace std;

Calculator::Calculator(App *app) :
leftOperand(""),
rightOperand(""),
action("") {
    this->app = app;
}

Calculator::Calculator(){};

void Calculator::makeCalc(bool isNewAction) {
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

bool Calculator::isNewAction(string action) {
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