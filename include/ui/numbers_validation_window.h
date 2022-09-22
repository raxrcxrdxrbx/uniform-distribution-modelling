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
#include "uniform_generator.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *m_ui;
    QString m_title = "Randomness tests";
    BarPlot *m_histogram;
    LinePlot *m_estimations;

    std::vector<QString> m_consistent = {"", "", ""};
    std::vector<QString> m_express = {"", "", ""};
    QString m_period_length;
    QString m_aperiodicity_segment;

/*// SIGNALS & SLOTS /////////////////////////////////////////*/
signals:
    void k_input_valueChanged(int k);

private slots:
    void on_k_input_valueChanged(int k);

};
#endif // MAINWINDOW_H
