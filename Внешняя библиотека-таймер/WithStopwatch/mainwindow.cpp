#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clock = new Clock(this);
    clock->setGeometry(0, 0, 200, 32);
    clock->show();
    clock->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
