
#include "ui/params_input_window.h"
#include "res/ui_params_input_window.h"

InputCustomParam::InputCustomParam(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::InputCustomParam) {

    m_ui->setupUi(this);
    setWindowIcon(m_icon);
    setWindowTitle(m_title);
    DisableUiCustomParamsInput(true);    
}
InputCustomParam::~InputCustomParam() {

    delete m_ui;
}

void InputCustomParam::DisableUiCustomParamsInput(bool flag) {

    m_ui->a_input->setReadOnly(flag);
    m_ui->m_input->setReadOnly(flag);
    m_ui->r0_input->setReadOnly(flag);
    m_ui->n_input->setReadOnly(flag);
}
bool InputCustomParam::IsCustomParamValidInt(const QString& param) {

    bool status = false;
    param.toULongLong(&status);

    return status;
}
/*// SIGNALS & SLOTS ///////////////////////////////////////////////////// */
void InputCustomParam::on_custom_params_button_clicked() {

   DisableUiCustomParamsInput(false);
}
void InputCustomParam::on_submit_button_pressed() {
	
    QMessageBox invalid_input_msg_box;
	invalid_input_msg_box.setIcon(QMessageBox::Critical);
	
    uint64_t a, m, n;
    float r0;

    if (m_ui->custom_params_button->isChecked()) {

        if(IsCustomParamValidInt(m_ui->a_input->displayText()) &&
            IsCustomParamValidInt(m_ui->m_input->displayText()) &&
            IsCustomParamValidInt(m_ui->r0_input->displayText()) &&
            IsCustomParamValidInt(m_ui->n_input->displayText())) {

            a = m_ui->a_input->displayText().toULongLong();
            m = m_ui->m_input->displayText().toULongLong();
            r0 = m_ui->r0_input->displayText().toULongLong();
            n = m_ui->n_input->displayText().toULongLong();
        }
        else {

            invalid_input_msg_box.setText("Entered parameters aren't valid.");
            invalid_input_msg_box.exec();
            return;
        }
    }
    else {

        if (m_ui->default_params_button->isChecked()) {

            a = 16807;
            m = 2147483647;
            r0 = 2836;
            n = 1000000;
        } 
        else {

            invalid_input_msg_box.setText("Choose the parameter type before proceeding.");
            invalid_input_msg_box.exec();
            return;
        }
    }

    LehmersGenerator::SetParams(a, m, r0);
    LehmersGenerator::SetSize(n);

    m_numbers_validation_window = new MainWindow(this);
    m_numbers_validation_window->setAttribute(Qt::WA_DeleteOnClose);
    m_numbers_validation_window->show();
}
void InputCustomParam::on_default_params_button_clicked() {

    DisableUiCustomParamsInput(true);
}


