#include <QApplication>

#include "include/ui/params_input_window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    InputCustomParam params_input_window;
    params_input_window.show();
    return app.exec();
}
