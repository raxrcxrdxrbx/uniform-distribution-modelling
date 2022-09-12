
#include "include/ui/numbers_validation_window.h"
#include "gui/ui_numbers_validation_window.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui ->setupUi(this);
}

MainWindow::~MainWindow() {

    delete ui;
}

bool MainWindow::PrepareUi() {

    MainWindow::CreateHistogram();
    bool is_tab_evaluation_ready = MainWindow::CreatePlot();

    return is_tab_evaluation_ready;
}


void MainWindow::CreateHistogram() {

    auto histogram_data = PrepareSamples();

    QBarSet *bar_set = new QBarSet("frequency");
    bar_set->append(histogram_data);

    QBarSeries *bar_series = new QBarSeries();
    if (!bar_series->append(bar_set)) {
        QMessageBox invalid_input_msg_box;
        invalid_input_msg_box.setIcon(QMessageBox::Critical);
        invalid_input_msg_box.setText("Invalid histogram data.");
        invalid_input_msg_box.exec();
        return;
    }

    QValueAxis *axis_y = new QValueAxis();
    axis_y->setRange(histogram_data.front(), histogram_data.back());
    axis_y->setLabelFormat("%.3f");

    QValueAxis *axis_x = new QValueAxis();
    axis_x->setRange(m_generator.GetMinNumber(), m_generator.GetMaxNumber());
    axis_x->setTickInterval(0.10);
    axis_x->setLabelFormat("%.3f");

    QChart *bar_chart = new QChart();
    bar_chart->addAxis(axis_x, Qt::AlignBottom);
    bar_chart->addAxis(axis_y, Qt::AlignLeft);
    bar_chart->addSeries(bar_series);

    QChartView *chart_view = new QChartView(bar_chart, ui->bar_chart);
    chart_view->setRenderHint(QPainter::Antialiasing);
    ui->bar_layout->addWidget(chart_view);
}

bool MainWindow::CreatePlot() {
    return true;
}

QList<qreal> MainWindow::PrepareSamples(int interval_count) {

    QList<qreal> result_frequencies;
    result_frequencies.reserve(interval_count);

    float min_random_number = m_generator.GetMinNumber();
    float max_random_number = m_generator.GetMaxNumber();
    float frequency_step = m_generator.GetIntervalRange();
    float number_count = (float)m_generator.GetSize();

    for (float interval_step = min_random_number; interval_step < max_random_number; interval_step += frequency_step) {

        result_frequencies.push_back(m_generator.GetFreaquency(interval_step, interval_step + frequency_step) / number_count);
    }

    return result_frequencies;
}

void MainWindow::EnableGenerator(int a, int m, int r0, size_t size) {

    m_generator.SetParams(a, m, r0);
    m_generator.SetSize(size);
    m_generator.Generate();
}

