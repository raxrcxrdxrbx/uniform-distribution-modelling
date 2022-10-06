
#include "ui/numbers_validation_window.h"
#include "res/ui_numbers_validation_window.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow) {

    LehmersGenerator::Generate();
    auto consistent_estimations = LehmersGenerator::GetConsistentEstimations();
    auto express_estimations = LehmersGenerator::GetExpressEstimations();

    m_ui->setupUi(this);
    m_ui->tab_widget->setCurrentIndex(0);
    setWindowTitle(m_title);

    m_histogram = new BarPlot(this);
    m_ui->bar_layout->addWidget(m_histogram);

    m_estimations = new LinePlot(this);
    m_ui->line_layout->addWidget(m_estimations);

    m_consistent[LehmersGenerator::MEAN] =
            QString::number(consistent_estimations[LehmersGenerator::MEAN]);
    m_ui->c_mean_line_edit->setText(m_consistent[LehmersGenerator::MEAN]);
    m_ui->c_mean_line_edit->setReadOnly(true);

    m_consistent[LehmersGenerator::VARIANCE] =
            QString::number(consistent_estimations[LehmersGenerator::VARIANCE]);
    m_ui->c_variance_line_edit->setText(m_consistent[LehmersGenerator::VARIANCE]);
    m_ui->c_variance_line_edit->setReadOnly(true);

    m_consistent[LehmersGenerator::STANDARD_DEVIATION] =
            QString::number(consistent_estimations[LehmersGenerator::STANDARD_DEVIATION]);
    m_ui->c_standard_deviation_line_edit->setText(m_consistent[LehmersGenerator::STANDARD_DEVIATION]);
    m_ui->c_standard_deviation_line_edit->setReadOnly(true);

    m_express[LehmersGenerator::MEAN] =
            QString::number(express_estimations[LehmersGenerator::MEAN]);
    m_ui->e_mean_line_edit->setText(m_express[LehmersGenerator::MEAN]);
    m_ui->e_mean_line_edit->setReadOnly(true);

    m_express[LehmersGenerator::VARIANCE] =
            QString::number(express_estimations[LehmersGenerator::VARIANCE]);
    m_ui->e_variance_line_edit->setText(m_express[LehmersGenerator::VARIANCE]);
    m_ui->e_variance_line_edit->setReadOnly(true);

    m_express[LehmersGenerator::STANDARD_DEVIATION] =
            QString::number(express_estimations[LehmersGenerator::STANDARD_DEVIATION]);
    m_ui->e_standard_deviation_line_edit->setText(m_express[LehmersGenerator::STANDARD_DEVIATION]);
    m_ui->e_variance_line_edit->setReadOnly(true);

    m_period_length = QString::number(LehmersGenerator::GetPeriodLength());
    m_ui->p_line_edit->setText(m_period_length);
    m_ui->p_line_edit->setReadOnly(true);

    m_aperiodicity_segment = QString::number(LehmersGenerator::GetAperiodicitySegment());
    m_ui->l_line_edit->setText(m_aperiodicity_segment);
    m_ui->l_line_edit->setReadOnly(true);
}
MainWindow::~MainWindow() {

    delete m_ui;
}

/*// SIGNALS & SLOTS ///////////////////////////////////////////////////// */
void MainWindow::on_k_input_valueChanged(int k) {

    emit k_input_valueChanged(k);
}

