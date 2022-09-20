
#include "include/ui/params_input_window.h"
#include "gui/ui_params_input_window.h"

InputCustomParam::InputCustomParam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputCustomParam) {

    ui->setupUi(this);
    DisableUiCustomParamsInput(true);    
}

InputCustomParam::~InputCustomParam() {

    delete ui;
    delete numbers_validation_window;
}

void InputCustomParam::on_custom_params_button_clicked() {

   DisableUiCustomParamsInput(false);
}


void InputCustomParam::on_submit_button_pressed() {
	
    QMessageBox invalid_input_msg_box;
	invalid_input_msg_box.setIcon(QMessageBox::Critical);
	
	int a, m, r0, n;

    if (ui->custom_params_button->isChecked()) {

        if(IsCustomParamValid(ui->a_input->displayText()) &&
            IsCustomParamValid(ui->m_input->displayText()) &&
            IsCustomParamValid(ui->r0_input->displayText()) &&
            IsCustomParamValid(ui->n_input->displayText())) {

            a = ui->a_input->displayText().toInt();            
            m = ui->m_input->displayText().toInt();
            r0 = ui->r0_input->displayText().toInt();
            n = ui->n_input->displayText().toInt();
        }
        else {            
            invalid_input_msg_box.setText("Entered parameters aren't valid.");
            invalid_input_msg_box.exec();
            return;
        }
    }
    else {

        if (ui->default_params_button->isChecked()) {

            a = 3;
            m = 5;
            r0 = 1;
            n = 10;
        } 
		else {            
            invalid_input_msg_box.setText("Choose the parameter type before proceeding.");
            invalid_input_msg_box.exec();
            return;
        }
    }

    UniformGenerator::SetParams(a, m, r0);
    UniformGenerator::SetSize(n);
    numbers_validation_window = new MainWindow();
    numbers_validation_window->show();
}

void InputCustomParam::on_default_params_button_clicked() {

    DisableUiCustomParamsInput(true);
}

/////////////////////////////////////////////////////////////////

void InputCustomParam::DisableUiCustomParamsInput(bool flag) {

    ui->a_input->setReadOnly(flag);
    ui->m_input->setReadOnly(flag);
    ui->r0_input->setReadOnly(flag);
}

bool InputCustomParam::IsCustomParamValid(const QString& param) {

    bool status = false;
    param.toInt(&status);

    return status;
}
