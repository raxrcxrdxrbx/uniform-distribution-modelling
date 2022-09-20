
#include "include/ui/bar_plot.h"

BarPlot::BarPlot(QWidget *parent):
    QChartView(parent) {
    if (SetData()) {

        SetAxes();
        CreateChart();
        setChart(m_chart);
    }
}

bool BarPlot::SetData() {

    auto generated_frequencies = UniformGenerator::GetFrequencies();
    for (const auto& frequency : generated_frequencies) {

        m_data.push_back(qreal(frequency));
    }

    m_set = new QBarSet("frequency");
    m_set->append(m_data);

    m_series = new QBarSeries();
    if (!m_series->append(m_set)) {

        QMessageBox invalid_input_msg_box;
        invalid_input_msg_box.setIcon(QMessageBox::Critical);
        invalid_input_msg_box.setText("Invalid histogram data.");
        invalid_input_msg_box.exec();
        return false;
    }
    else {

        return true;
    }
}
void BarPlot::SetAxes() {

    m_ax = new QValueAxis();
    m_ax->setTickAnchor(UniformGenerator::GetMinNumber());
    m_ax->setTickInterval(UniformGenerator::GetIntervalRange());
    m_ax->setTickType(QValueAxis::TicksDynamic);
    m_ax->setLabelFormat("%.3f");
    m_ax->setRange(UniformGenerator::GetMinNumber(), UniformGenerator::GetMaxNumber());

    m_ay = new QValueAxis();
    m_ay->setTickAnchor(0);
    m_ay->setTickInterval(0.5);
    m_ay->setTickType(QValueAxis::TicksDynamic);
    m_ay->setLabelFormat("%.3f");
    m_ay->setRange(*std::min_element(m_data.begin(), m_data.end()), *std::max_element(m_data.begin(), m_data.end()));
}
void BarPlot::CreateChart() {

    m_chart = new QChart();
    m_chart->addAxis(m_ax, Qt::AlignBottom);
    m_chart->addAxis(m_ay, Qt::AlignLeft);
    m_chart->addSeries(m_series);
}
