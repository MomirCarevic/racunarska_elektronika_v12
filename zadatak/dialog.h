#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCharts/QChartsView>
#include <QCharts/QValueAxis>
#include <QCharts/QLineSeries>
#include <QTimer>
#include <QTime>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void izlaz();
private:
    Ui::Dialog *ui;
    QTimer *tajmer;
    QValueAxis *xosa;
    QValueAxis *yosa;
    QChartView *chartView;
    QChart *chart;
    QLineSeries *series;
};
#endif // DIALOG_H
