#ifndef LINE_PLOT_H
#define LINE_PLOT_H

#include <QtCharts>
#include <cmath>

#include "lehmers_generator.h"

//! A LinePlot class.
/*!
 *  \brief Prepares a chart which displays random number pairs with respect to a circle inscribed in a square.
*/
class LinePlot : public QChartView {

    Q_OBJECT

public:
    //! A constructor.
    explicit LinePlot(QWidget *parent = nullptr);

private:
    //! Stores a pointer to QLineSeries for drawing the square.
    QLineSeries *m_square_series = new QLineSeries();

    //! Stores a pointer to QLineSeries for drawing the circle.
    QLineSeries *m_circle_series = new QLineSeries();

    //! Stores a pointer to QScatterSeries for drawing random number pairs.
    QScatterSeries *m_series = new QScatterSeries();

    //! Stores a pointer to QValueAxis for drawing horizontal axis.
    QValueAxis *m_ax = new QValueAxis();

    //! Stores a pointer to QValueAxis for drawing vertical axis.
    QValueAxis *m_ay = new QValueAxis();

    //! Stores a pointer to the graphical representation of series and axes.
    QChart *m_chart = new QChart();

    //! Stores converted generated random number pairs.
    QList<QPointF> m_data;

    //! Prepares circle series.
    void SetCircle();

    //! Prepares square series.
    void SetSquare();

    //! Prepares random number pairs series.
    void SetData();
};
#endif // LINE_PLOT_H
