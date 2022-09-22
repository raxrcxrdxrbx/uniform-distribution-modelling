#ifndef LINE_PLOT_H
#define LINE_PLOT_H

#include <QtCharts>
#include <cmath>

#include "uniform_generator.h"

class LinePlot : public QChartView {

    Q_OBJECT

public:
    explicit LinePlot(QWidget *parent = nullptr);

private:
    QLineSeries *m_square_series = new QLineSeries();
    QLineSeries *m_circle_series = new QLineSeries();
    QScatterSeries *m_series = new QScatterSeries();
    QValueAxis *m_ax = new QValueAxis();
    QValueAxis *m_ay = new QValueAxis();
    QChart *m_chart = new QChart();

    QList<QPointF> m_data;

    void SetCircle();
    void SetSquare();
    void SetData();
};
#endif // LINE_PLOT_H
