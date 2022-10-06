#ifndef BAR_PLOT_H
#define BAR_PLOT_H

#include <QtCharts>
#include <QList>
#include <QtGlobal>

#include "lehmers_generator.h"

//! A BarPlot class.
/*!
 *  \brief Prepares a chart which displays "relative" frequencies showing the proportion of random numbers that fall into each interval.
*/
class BarPlot : public QChartView {

    Q_OBJECT

public:
    //! A constructor.
    explicit BarPlot(QWidget *parent = nullptr);

private:
    //! Stores a pointer to set of "relative" frequencies.
    QBarSet *m_set = new QBarSet("frequency");

    //! Stores a pointer QBarSeries for drawing bars.
    QBarSeries *m_series = new QBarSeries();

    //! Stores a pointer to QValueAxis for drawing horizontal axis.
    QValueAxis *m_ax = new QValueAxis();

    //! Stores a pointer to QValueAxis for drawing vertical axis.
    QValueAxis *m_ay = new QValueAxis();

    //! Stores a pointer to the graphical representation of series and axes.
    QChart *m_chart = new QChart();

    //! Stores converted generated "relative" frequencies.
    QList<qreal> m_bar_data;

    //! Prepares "relative" frequencies series.
    /*!
     *  \param interval_count number of intervals to be dislayed
     *  \return status of data setting
     */
    bool SetData(int interval_count = 5);

    //! Prepares axes.
    /*!
    *   \param interval_ticks_count number of interval ticks to be dislayed
    */
    void SetAxes(int interval_ticks_count = 6);

public slots:

    //! Changes chart according to emitted signal by MainWindow.
    void on_k_input_valueChanged(int k);
};
#endif // BAR_PLOT_H
