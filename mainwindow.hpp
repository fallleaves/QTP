#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Core/core.hpp>
#include <memory>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    MainWindow(const MainWindow&) = delete;
    MainWindow(MainWindow&&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    MainWindow& operator=(MainWindow&&) = delete;

private:
    void processFile();

private slots:
    void onGenerateFile();
    void onShow();
    void onStop();
    void onTimerTimeOut();
    void onContinue();

private:
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<QTP::core::Core> core;
    std::unique_ptr<QTimer> timer;
};

#endif // MAINWINDOW_H
