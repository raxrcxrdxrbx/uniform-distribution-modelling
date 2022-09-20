
#include "include/ui/bar_plot.h"

BarPlot::BarPlot(QWidget *parent):
    QChartView(parent) {

    connect(parent, SIGNAL(k_input_valueChanged(int)), this, SLOT(on_k_input_valueChanged(int)));

    if (SetData()) {

        SetAxes();
        m_chart->addAxis(m_ax, Qt::AlignBottom);
        m_chart->addAxis(m_ay, Qt::AlignLeft);
        m_chart->addSeries(m_series);
        setChart(m_chart);
        setRenderHint(QPainter::Antialiasing);
    }
}

bool BarPlot::SetData(int interval_count) {

    auto generated_frequencies = UniformGenerator::GetFrequencies(interval_count);
    for (const auto& frequency : generated_frequencies) {

        m_data.push_back(qreal(frequency));
    }

    m_set->append(m_data);
    if (!m_series->append(m_set) && m_series->barSets().empty()) {

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
void BarPlot::SetAxes(int interval_count) {

    m_ax->setTickCount(interval_count);
    m_ax->setTickType(QValueAxis::TicksFixed);
    m_ax->setLabelFormat("%.3f");
    m_ax->setMin(UniformGenerator::GetMinNumber());
    m_ax->setMax(UniformGenerator::GetMaxNumber());

    m_ay->setTickAnchor(0);
    m_ay->setTickInterval(0.5);
    m_ay->setTickType(QValueAxis::TicksDynamic);
    m_ay->setLabelFormat("%.3f");
    m_ay->setMin(*std::min_element(m_data.begin(), m_data.end()));
    m_ay->setMax(*std::max_element(m_data.begin(), m_data.end()));
}

void BarPlot::on_k_input_valueChanged(int k) {

    m_chart->removeAxis(m_ax);
    m_chart->removeAxis(m_ay);
    m_chart->removeSeries(m_series);

    m_set->remove(0, m_data.size());
    m_data.clear();

    if (SetData(k)) {

        SetAxes(k + 1);
        m_chart->addAxis(m_ax, Qt::AlignBottom);
        m_chart->addAxis(m_ay, Qt::AlignLeft);
        m_chart->addSeries(m_series);
        repaint();
    }
}
