#ifndef APP_H
#define APP_H
#include <map>
#include <string>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Output.H>
using namespace std;

class App {
public:
    Fl_Window *flWindow;
    map< string, Fl_Box* > flBox;
    map< string, Fl_Button*> flButtons;
    string leftOperand= "";
    string action= "";
    string rightOperand= "";
    int argc;
    char **argv;
    Fl_Output *output;

    App(int argc, char **argv);
    void run();
    static void myCallback(Fl_Widget *w, void *data);
    static void resetOutput(Fl_Widget *w, void *data);
private:
    void startWindow();
    void endWindow();
    void createBox(int x, int y, int width, int height, string title);
    void createBotton(int x, int y, int width, int height, string title);
    bool isNewAction(string action);
    
};

#endif /* APP_H */

