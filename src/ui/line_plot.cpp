
#include "ui/line_plot.h"

LinePlot::LinePlot(QWidget *parent):
    QChartView(parent) {

    SetData();
    m_chart->addSeries(m_series);
    m_chart->addSeries(m_square_series);
    m_chart->addSeries(m_circle_series);

    m_chart->createDefaultAxes();
    m_chart->setDropShadowEnabled(false);
    m_chart->legend()->setVisible(false);
    setChart(m_chart);
    setRenderHint(QPainter::Antialiasing);
}

void LinePlot::SetCircle() {

    for (float x = 0.0; x < 1.0; x += 0.01) {

        m_circle_series->append(x, std::sqrt(1.0 - x*x));
    }
}
void LinePlot::SetSquare() {

    m_square_series->append(0.0, 1.0);
    m_square_series->append(1.0, 1.0);
    m_square_series->append(1.0, 0.0);

}
void LinePlot::SetData() {

    SetSquare();
    SetCircle();
    m_series->setName("pairs");
    m_series->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    m_series->setMarkerSize(5.0);

    auto generated_pairs = LehmersGenerator::GetPairs();
    for (const auto& pair : generated_pairs) {

        m_series->append(pair.first, pair.second);
    }
}
