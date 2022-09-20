#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QMainWindow>
#include <QList>
#include <QtGlobal>

#include <QBarSet>
#include <QBarSeries>
#include <QValueAxis>
#include <QChartView>

#include <QMessageBox>

#include "bar_plot.h"
#include "uniform_generator.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {

    Q_OBJECT

signals:
    void k_input_valueChanged(int k);

private slots:
    void on_k_input_valueChanged(int k);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BarPlot *m_histogram;
};
#endif // MAINWINDOW_H
