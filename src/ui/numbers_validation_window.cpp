
#include "include/ui/numbers_validation_window.h"
#include "gui/ui_numbers_validation_window.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    UniformGenerator::Generate();
    ui ->setupUi(this);

    m_histogram = new BarPlot();
    m_histogram->setRenderHint(QPainter::Antialiasing);
    ui->bar_layout->addWidget(m_histogram);
}

MainWindow::~MainWindow() {

    delete ui;
}


