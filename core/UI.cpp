#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Output.H>
#include <FL/fl_draw.H>
#include "UI.h"
#include "App.h"

using namespace std;

UI::UI(App* app) {
    this->app = app;
}

UI::UI(){}

void UI::startWindow() {
    Fl_Window *window = new Fl_Window(400, 300, "Calculator");
    this->flWindow = window;
}

void UI::createUI() {
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
    void * self = (void *) this->app;
    button0 ->callback(UI::clickButton, self);
    button1 ->callback(UI::clickButton, self);
    button2 ->callback(UI::clickButton, self);
    button3 ->callback(UI::clickButton, self);
    button4 ->callback(UI::clickButton, self);
    button5 ->callback(UI::clickButton, self);
    button6 ->callback(UI::clickButton, self);
    button7 ->callback(UI::clickButton, self);
    button8 ->callback(UI::clickButton, self);
    button9 ->callback(UI::clickButton, self);
    plus ->callback(UI::clickButton, self);
    minus ->callback(UI::clickButton, self);
    divide ->callback(UI::clickButton, self);
    equal ->callback(UI::clickButton, self);
    reset ->callback(UI::resetOutput, self);
    multiply->callback(UI::clickButton, self);
}

void UI::clickButton(Fl_Widget* w, void* data) {
    App *app = ((App *) data);
    const char * insertedRawValue = w->label();
    string insertedValue = (string) insertedRawValue;
    bool isNewAction = app->calc.isNewAction(insertedValue);

    app->calc.makeCalc(isNewAction);
    app->prepareOutput(insertedValue, isNewAction);
    app->ui.changeOutputValue();
}

void UI::changeOutputValue() {
    string result = this->app->calc.leftOperand + this->app->calc.action + this->app->calc.rightOperand;
    this->output->value(result.c_str());
}

void UI::resetOutput(Fl_Widget* w, void* data) {
    App *app = ((App *) data);
    app->calc.leftOperand = "";
    app->calc.action = "";
    app->calc.rightOperand = "";
    app->ui.output->value("");
}

void UI::endWindow() {
    this->flWindow->end();
    this->flWindow->show(this->app->argc, this->app->argv);
    Fl::run();
}