#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QtGlobal>

#include <QBarSet>
#include <QBarSeries>
#include <QValueAxis>
#include <QChartView>

#include <QMessageBox>

#include "bar_plot.h"
#include "line_plot.h"
#include "lehmers_generator.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

//! A MainWindow class.
/*!
 *  \brief Aggregates estimated results of generated numbers.
*/
class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    //! A constructor.
    MainWindow(QWidget *parent = nullptr);

    //! A destructor.
    ~MainWindow();

private:
    //! Stores a pointer to ui elements.
    Ui::MainWindow *m_ui;

    //! Title of the window.
    QString m_title = "Randomness tests";

    //! Stores a pointer to histogram or BarChart.
    BarPlot *m_histogram;

    //! Stores a pointer to line-scatter plot or Line/ScatterChart.
    LinePlot *m_estimations;

    //! Stores converted consistent estimations.
    std::vector<QString> m_consistent = {"", "", ""};

    //! Stores converted express estimations.
    std::vector<QString> m_express = {"", "", ""};

    //! Stores converted count of repeating random numbers.
    QString m_period_length;

    //! Stores converted count of unique random numbers.
    QString m_aperiodicity_segment;

signals:
    //! Signal for BarPlot slot.
    void k_input_valueChanged(int k);

private slots:
    //! Reacts to interval count change by user.
    void on_k_input_valueChanged(int k);

};
#endif // MAINWINDOW_H
