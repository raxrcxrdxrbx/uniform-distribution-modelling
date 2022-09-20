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
    QBarSet *m_set = nullptr;
    QBarSeries *m_series = nullptr;
    QValueAxis *m_ax = nullptr, *m_ay = nullptr;
    QChart *m_chart = nullptr;
    QChartView *m_view = nullptr;

    QList<qreal> m_data;

    bool SetData();
    void SetAxes();
    void CreateChart();
};

#endif // BAR_PLOT_H
