#include "dialog.h"
#include "ui_dialog.h"

float voltage;
int i =1;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    series = new QLineSeries();
    series -> append(0,0);

            //GRAFIK
    chart = new QChart();
    chart -> legend() -> hide();
    chart -> addSeries(series);
    chart -> setTitle("Prikaz promene napona na potenciometru:");

    xosa = new QValueAxis();
    yosa = new QValueAxis();
    xosa -> setRange(0,5);
    yosa -> setRange(0,4);

    chart -> addAxis(xosa,Qt::AlignBottom);
    chart -> addAxis(yosa,Qt::AlignLeft);
    series -> attachAxis(xosa);
    series -> attachAxis(yosa);

    chartView = new QChartView(chart);
    chartView -> setRenderHint(QPainter::Antialiasing);
    chartView -> setParent(ui->horizontalFrame);

    tajmer = new QTimer(this);
    connect(tajmer,&QTimer::timeout,this,&Dialog::izlaz);


}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    tajmer -> stop();
    series -> clear();
    i = 1;
}


void Dialog::on_pushButton_2_clicked()
{
    tajmer -> start(1000);
    series -> append(0,0);
}

void senzor()
{
    if(wiringPiSetup() == -1)
        exit(1);
    int fd = wiringPiI2CSetup(0x48);
    voltage = wiringPiI2CReadReg8(fd,0x48+3);
}

void Dialog::izlaz()
{

    i++;

    senzor();
    voltage = voltage * 3.3 / 255;

    series -> append(i,voltage);

}

