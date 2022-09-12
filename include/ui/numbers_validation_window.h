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

#include "uniform_generator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool PrepareUi();
    void EnableGenerator(int a, int m, int r0, size_t size);

private:
    Ui::MainWindow *ui;
    UniformGenerator m_generator;

    void CreateHistogram();
    bool CreatePlot();
    QList<qreal> PrepareSamples(int interval_count = 5);
};
#endif // MAINWINDOW_H
