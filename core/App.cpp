#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <iostream>
#include <sstream>
#include <map>
#include "App.h"
#include <FL/fl_draw.H>
using namespace std;

App::App(int argc, char **argv) :
leftOperand(""),
rightOperand(""),
action("") {
    this->argc = argc;
    this->argv = argv;
}

void App::run() {
    startWindow();
    createUI();
    endWindow();
}

void App::startWindow() {
    Fl_Window *window = new Fl_Window(400, 300, "Calculator");
    this->flWindow = window;
}

void App::createUI() {
    Fl_Button *button0 = new Fl_Button(150, 190, 50, 25, "0");
    Fl_Button *button1 = new Fl_Button(100, 100, 50, 25, "1");
    Fl_Button *button2 = new Fl_Button(150, 100, 50, 25, "2");
    Fl_Button *button3 = new Fl_Button(200, 100, 50, 25, "3");
    Fl_Button *button4 = new Fl_Button(100, 130, 50, 25, "4");
    Fl_Button *button5 = new Fl_Button(150, 130, 50, 25, "5");
    Fl_Button *button6 = new Fl_Button(200, 130, 50, 25, "6");
    Fl_Button *button7 = new Fl_Button(100, 160, 50, 25, "7");
    Fl_Button *button8 = new Fl_Button(150, 160, 50, 25, "8");
    Fl_Button *button9 = new Fl_Button(200, 160, 50, 25, "9");
    Fl_Button *plus = new Fl_Button(250, 100, 50, 25, "+");
    Fl_Button *minus = new Fl_Button(250, 130, 50, 25, "-");
    Fl_Button *divide = new Fl_Button(250, 160, 50, 25, "/");
    Fl_Button *equal = new Fl_Button(250, 190, 50, 25, "=");
    Fl_Output *output = new Fl_Output(50, 20, 300, 25, "Result");
    Fl_Button *reset = new Fl_Button(250, 75, 50, 25, "C");
    Fl_Button *multiply = new Fl_Button(200, 190, 50, 25, "*");

    this->output = output;
    void * self = (void *) this;
    button0 ->callback(App::clickButton, self);
    button1 ->callback(App::clickButton, self);
    button2 ->callback(App::clickButton, self);
    button3 ->callback(App::clickButton, self);
    button4 ->callback(App::clickButton, self);
    button5 ->callback(App::clickButton, self);
    button6 ->callback(App::clickButton, self);
    button7 ->callback(App::clickButton, self);
    button8 ->callback(App::clickButton, self);
    button9 ->callback(App::clickButton, self);
    plus ->callback(App::clickButton, self);
    minus ->callback(App::clickButton, self);
    divide ->callback(App::clickButton, self);
    equal ->callback(App::clickButton, self);
    reset ->callback(App::resetOutput, self);
    multiply->callback(App::clickButton, self);
}

void App::clickButton(Fl_Widget* w, void* data) {
    App *app = ((App *) data);
    const char * insertedRawValue = w->label();
    string insertedValue = (string) insertedRawValue;
    bool isNewAction = app->isNewAction(insertedValue);

    app->makeCalc(isNewAction);
    app->prepareOutput(insertedValue, isNewAction);
    app->changeOutputValue();
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

void App::changeOutputValue() {
    string result = this->leftOperand + this->action + this->rightOperand;
    this->output->value(result.c_str());
}

void App::resetOutput(Fl_Widget* w, void* data) {
    App *app = ((App *) data);
    app->leftOperand = "";
    app->action = "";
    app->rightOperand = "";
    app->output->value("");
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

void App::endWindow() {
    this->flWindow->end();
    this->flWindow->show(this->argc, this->argv);
    Fl::run();
}
