#ifndef UI_H
#define UI_H

#include <string>
#include <map>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
using namespace std;
class App;

class UI {
public:
    UI(App*);
    UI();
    App *app;
    Fl_Window *flWindow;
    map< string, Fl_Box* > flBox;
    map< string, Fl_Button*> flButtons;
    Fl_Output *output;
    void startWindow();
    void createUI();
    void endWindow();
    void changeOutputValue();
    static void resetOutput(Fl_Widget *w, void *data);
    static void clickButton(Fl_Widget *w, void *data);
};

#endif /* UI_H */

