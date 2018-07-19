#include "App.h"
#include "UI.h"
#include "Calculator.h"

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