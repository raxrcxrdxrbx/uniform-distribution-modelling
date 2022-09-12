#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "numbers_validation_window.h"

namespace Ui {
    class InputCustomParam;
}

class InputCustomParam : public QDialog {
    Q_OBJECT

public:
    explicit InputCustomParam(QWidget *parent = nullptr);
    ~InputCustomParam();

private slots:
    void on_custom_params_button_clicked();
    void on_default_params_button_clicked();

    void on_submit_button_pressed();


private:
    Ui::InputCustomParam *ui;
    MainWindow *numbers_validation_window;

    void DisableUiCustomParamsInput(bool flag);
    bool IsCustomParamValid(const QString& param);
};

#endif // DIALOG_H
