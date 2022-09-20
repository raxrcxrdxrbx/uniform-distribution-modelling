
#include "include/ui/numbers_validation_window.h"
#include "gui/ui_numbers_validation_window.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    UniformGenerator::Generate();

    ui->setupUi(this);
    m_histogram = new BarPlot(this);

    ui->bar_layout->addWidget(m_histogram);
}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::on_k_input_valueChanged(int k) {

    emit k_input_valueChanged(k);
}
