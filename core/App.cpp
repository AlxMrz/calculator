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

//string App::leftOperand = "";
//string App::action = "";
//string App::rightOperand = "";

App::App(int argc, char **argv) : leftOperand(""), rightOperand(""), action("") {
    this->argc = argc;
    this->argv = argv;
}

void App::run() {
    this->startWindow();
    this->createBox(0, 400, 300, 100, "Insert");
    //    this->createBox(300, 40, 300, 100, "Second");
    //    this->createBox(600, 40, 300, 100, "Third");
    this->createBotton(0, 40, 300, 100, "Hello, World!");
    this->endWindow();
}

void App::startWindow() {
    Fl_Window *window = new Fl_Window(400, 300, "Calculator");
    this->flWindow = window;
}

void App::createBox(int x, int y, int width, int height, string title) {
    Fl_Box *box = new Fl_Box(x, y, width, height, "HHello world");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD + FL_ITALIC);
    box->labelsize(36);
    box->labeltype(FL_SHADOW_LABEL);
    this->flBox[title] = box;
}

void App::endWindow() {
    this->flWindow->end();
    this->flWindow->show(this->argc, this->argv);
    Fl::run();
}

void App::createBotton(int x, int y, int width, int height, string title) {
    Fl_Button *button0  = new Fl_Button(150, 190, 50, 25, "0");
    Fl_Button *button1  = new Fl_Button(100, 100, 50, 25, "1");
    Fl_Button *button2  = new Fl_Button(150, 100, 50, 25, "2");
    Fl_Button *button3  = new Fl_Button(200, 100, 50, 25, "3");
    Fl_Button *button4  = new Fl_Button(100, 130, 50, 25, "4");
    Fl_Button *button5  = new Fl_Button(150, 130, 50, 25, "5");
    Fl_Button *button6  = new Fl_Button(200, 130, 50, 25, "6");
    Fl_Button *button7  = new Fl_Button(100, 160, 50, 25, "7");
    Fl_Button *button8  = new Fl_Button(150, 160, 50, 25, "8");
    Fl_Button *button9  = new Fl_Button(200, 160, 50, 25, "9");
    Fl_Button *plus     = new Fl_Button(250, 100, 50, 25, "+");
    Fl_Button *minus    = new Fl_Button(250, 130, 50, 25, "-");
    Fl_Button *devide   = new Fl_Button(250, 160, 50, 25, "/");
    Fl_Button *equal    = new Fl_Button(250, 190, 50, 25, "=");
    Fl_Output *output   = new Fl_Output(50, 20, 300, 25, "Result");
    Fl_Button *reset    = new Fl_Button(250, 75, 50, 25, "C");
    Fl_Button *multiply = new Fl_Button(200, 190, 50, 25, "*");
    
    this->output = output;
    
    button0 ->callback(App::myCallback, (void *) this);
    button1 ->callback(App::myCallback, (void *) this);
    button2 ->callback(App::myCallback, (void *) this);
    button3 ->callback(App::myCallback, (void *) this);
    button4 ->callback(App::myCallback, (void *) this);
    button5 ->callback(App::myCallback, (void *) this);
    button6 ->callback(App::myCallback, (void *) this);
    button7 ->callback(App::myCallback, (void *) this);
    button8 ->callback(App::myCallback, (void *) this);
    button9 ->callback(App::myCallback, (void *) this);
    plus    ->callback(App::myCallback, (void *) this);
    minus   ->callback(App::myCallback, (void *) this);
    devide  ->callback(App::myCallback, (void *) this);
    equal   ->callback(App::myCallback, (void *) this);
    reset   ->callback(App::resetOutput,(void *) this);
    multiply->callback(App::myCallback, (void *) this);
}

void App::myCallback(Fl_Widget* w, void* data) {
    App *app = ((App *) data);
    const char * current = app->output->value();
    const char * inserted = w->label();
    bool isNewAction = app->isNewAction((string) inserted);
    double endValue = 0;
    if (app->leftOperand != "" && app->rightOperand != "" && app->action != "" && isNewAction) {
        if (app->action == "+") {
            endValue = atof(app->leftOperand.c_str()) + atof(app->rightOperand.c_str());
            app->rightOperand = "";
        } else if (app->action == "-") {
            endValue = atof(app->leftOperand.c_str()) - atof(app->rightOperand.c_str());
            app->rightOperand = "";
        } else if (app->action == "/") {
            endValue = atof(app->leftOperand.c_str()) / atof(app->rightOperand.c_str());
            app->rightOperand = "";
        } else if (app->action == "*") {
            endValue = atof(app->leftOperand.c_str()) * atof(app->rightOperand.c_str());
            app->rightOperand = "";
        }
        app->action = "";
        ostringstream strs;
        strs << endValue;
        string str = strs.str();
        app->leftOperand = str;

    } else if (app->action != "" && !isNewAction) {
        app->rightOperand += (string) inserted;
    } else if (!isNewAction) {
        app->leftOperand += (string) inserted;
    }
    
    if(isNewAction && app->rightOperand == "" && (string)inserted != "=") {
        app->action = (string)inserted;
    }
    string result = app->leftOperand + app->action + app->rightOperand;
    app->output->value(result.c_str());
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
    if (    action == "+" ||
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