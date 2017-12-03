#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <Tools/datagenerator.hpp>

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui{std::make_unique<Ui::MainWindow>()}
    , core{std::make_unique<QTP::core::Core>()}
    , timer{std::make_unique<QTimer>(nullptr)}
{
    ui->setupUi(this);

    ui->label_1->setText("钢丝绳 1");
    ui->label_2->setText("钢丝绳 2");
    ui->label_3->setText("钢丝绳 3");
    ui->label_4->setText("钢丝绳 4");
    ui->label_5->setText("压力 1");
    ui->label_6->setText("压力 2");

    ui->plainTextEdit_force_weight_ratio->setReadOnly(true);
    ui->plainTextEdit_theoretical_force->setReadOnly(true);

    connect(timer.get(), SIGNAL(timeout()), this, SLOT(onTimerTimeOut()));
    connect(ui->actionShow, SIGNAL(triggered()), this, SLOT(onShow()));
    connect(ui->actionGenerateFile, SIGNAL(triggered()), this, SLOT(onGenerateFile()));
    connect(ui->actionStop, SIGNAL(triggered()), this, SLOT(onStop()));
    connect(ui->actionContinue, SIGNAL(triggered()), this, SLOT(onContinue()));

    MainWindow::showMaximized();
    ui->splitter->setSizes(QList<int>({1, 1}));
    timer->setInterval(250);
}

MainWindow::~MainWindow()
{
    timer->stop();
}

void MainWindow::onGenerateFile()
{
    core->getDataGenerator().generateRandom("data.txt", ";");
}

// TODO do the following in separate thread
void MainWindow::onShow()
{
    processFile();
    timer->start();
}

void MainWindow::processFile()
{
    QRegExp rx("(\\,|\\n)");
    core->getInputManager().readFile("1118.csv", rx);
    core->getInputManager().reset();
}

void MainWindow::onTimerTimeOut()
{
    const auto& data = core->getInputManager().getNextData();

    QDateTime timestamp;
    timestamp.setTime_t(data.timestamp);
    const auto time = timestamp.toUTC().toString(Qt::SystemLocaleLongDate);

    // udpdate timestamp
    ui->label_timestamp->setText(time);

    // update cord information
    ui->label_cord_1->setText(QString::number(data.length1));
    ui->progressBar_cord_1->setValue(static_cast<uint32_t>(data.length1));
    ui->label_cord_2->setText(QString::number(data.length2));
    ui->progressBar_cord_2->setValue(static_cast<uint32_t>(data.length2));
    ui->label_cord_3->setText(QString::number(data.length3));
    ui->progressBar_cord_3->setValue(static_cast<uint32_t>(data.length3));
    ui->label_cord_4->setText(QString::number(data.length4));
    ui->progressBar_cord_4->setValue(static_cast<uint32_t>(data.length4));

    // update cage depth
    ui->label_cage_depth->setText(QString::number(data.cageDepth));
    ui->progressBar_cage_depth->setValue(static_cast<int32_t>(data.cageDepth));

    // update pressure
    ui->label_pressure1->setText(QString::number(data.pressure1));
    ui->label_pressure2->setText(QString::number(data.pressure2));
    ui->progressBar_pressure1->setValue(static_cast<uint32_t>(data.pressure1));
    ui->progressBar_pressure2->setValue(static_cast<uint32_t>(data.pressure2));
}

void MainWindow::onStop()
{

    timer->stop();
}

void MainWindow::onContinue()
{
    timer->start();
}
