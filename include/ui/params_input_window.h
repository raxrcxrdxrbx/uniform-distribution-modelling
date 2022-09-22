#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QIcon>

#include "numbers_validation_window.h"

namespace Ui {
    class InputCustomParam;
}

class InputCustomParam : public QDialog {
    Q_OBJECT

public:
    explicit InputCustomParam(QWidget *parent = nullptr);
    ~InputCustomParam();

private:
    Ui::InputCustomParam *m_ui;
    MainWindow *m_numbers_validation_window;

    QIcon m_icon = QIcon(":/icons/lab1_icon.png");
    QString m_title = "Parameters' input";

    void DisableUiCustomParamsInput(bool flag);
    bool IsCustomParamValid(const QString& param);

/*// SIGNALS & SLOTS /////////////////////////////////////////*/
private slots:
    void on_custom_params_button_clicked();
    void on_default_params_button_clicked();
    void on_submit_button_pressed();
};

#endif // DIALOG_H
