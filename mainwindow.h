#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QKeyEvent>

#include <iostream>
#include <sstream>
#include <string>

#include "outputmanager.h"
#include "direction.h"

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setOutputManager(OutputManager *output);

protected :
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    OutputManager *output;
    void joypadCamera(float x, float y);
    void turnCamera(Direction direction, float speed);
    void joypadRobot(float x, float y);
    void moveRobot(Direction direction, float speed);

private slots:
    void on_connectionBtn_pressed();
};

#endif // MAINWINDOW_H
