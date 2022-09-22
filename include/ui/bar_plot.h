#ifndef BAR_PLOT_H
#define BAR_PLOT_H

#include <QtCharts>
#include <QList>
#include <QtGlobal>

#include "uniform_generator.h"

class BarPlot : public QChartView {

    Q_OBJECT

public:
    explicit BarPlot(QWidget *parent = nullptr);

private:
    QBarSet *m_set = new QBarSet("frequency");
    QBarSeries *m_series = new QBarSeries();
    QValueAxis *m_ax = new QValueAxis();
    QValueAxis *m_ay = new QValueAxis();
    QChart *m_chart = new QChart();

    QList<qreal> m_bar_data;

    bool SetData(int interval_count = 5);
    void SetAxes(int interval_ticks_count = 6);

/*// SIGNALS & SLOTS /////////////////////////////////////////*/
public slots:
    void on_k_input_valueChanged(int k);
};

#endif // BAR_PLOT_H
