#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QIcon>

#include "numbers_validation_window.h"

namespace Ui {
    class InputCustomParam;
}

//! A InputCustomParam class.
/*!
 *  \brief Creates a custom dialog window first to appear after launching. Parameters necessary for generation are entered and processed here.
 */

class InputCustomParam : public QDialog {
    Q_OBJECT

public:
    //! A constructor.
    explicit InputCustomParam(QWidget *parent = nullptr);

    //! A destructor.
    ~InputCustomParam();

private:
    //! Stores a pointer to ui elements.
    Ui::InputCustomParam *m_ui;

    //! Stores a pointer to child window created after parameters validation.
    MainWindow *m_numbers_validation_window;

    //! Program icon (child window inherits it).
    QIcon m_icon = QIcon(":/icons/lab1_icon.png");

    //! Title of the window.
    QString m_title = "Parameters' input";

    //! Disables or enables user input for custom parameters.
    /*!
     *  \param flag is used for switching function modes (disable or enable)
    */
    void DisableUiCustomParamsInput(bool flag);

    //! Varifies whether QString can be converted to integer number.
    /*!
     *  \param param stores a QString
     *  \return status of convertion attempt
    */
    bool IsCustomParamValidInt(const QString& param);

private slots:
    //! Reacts to the mouse click on custom params radio button by user.
    void on_custom_params_button_clicked();

    //! Reacts to the mouse click on default params radio button by user.
    void on_default_params_button_clicked();

    //! Reacts to the mouse click on submit button by user.
    void on_submit_button_pressed();
};
#endif // DIALOG_H
