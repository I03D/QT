#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QTimer>

#include <QWidget>
#include <QLCDNumber>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    clock = new Clock(this);
    clock->setGeometry(10, 130, 361, 31);
    clock->show();

    timer = new QTimer(this);

    timer->setInterval(1000);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));

    connect(ui->pushButton22, SIGNAL(clicked()), this, SLOT(on_btn_click()));
    connect(ui->pushButton222, SIGNAL(clicked()), this, SLOT(on_btn_click2()));

    connect(ui->Start, SIGNAL(clicked()), this, SLOT(b_start()));
    connect(ui->Stop, SIGNAL(clicked()), this, SLOT(b_stop()));
    connect(ui->Reset, SIGNAL(clicked()), this, SLOT(b_reset()));
    connect(ui->Reset_2, SIGNAL(clicked()), this, SLOT(b_set()));
    connect(ui->Reset_3, SIGNAL(clicked()), this, SLOT(b_alarm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::b_alarm() {
    clock->set_alarm(ui->lineEdit_4->text().toInt());
}

void MainWindow::b_set() {
    clock->set(ui->lineEdit_4->text().toInt());
}

void MainWindow::b_start() {
    clock->start();
}

void MainWindow::b_stop() {
    clock->stop();
}

void MainWindow::b_reset() {
    clock->reset();
}

void MainWindow::on_timer() {
    QString time = QTime::currentTime().toString("hh:mm:ss");
    ui->lcdNumber->display(time);
}

void MainWindow::on_btn_click()
{
    QString name = ui->lineEdit->text();

    QMessageBox msg;
    msg.setText("Привет, " + name + "!!");
    msg.exec();
}

void MainWindow::on_btn_click2()
{
    float x = ui->lineEdit_2->text().toFloat();
    float y = ui->lineEdit_3->text().toFloat();
    float result;
    bool error = false;

    if (ui->comboBox->currentText() == "+") {
        result = x + y;
    } else if (ui->comboBox->currentText() == "-") {
        result = x - y;
    } else if (ui->comboBox->currentText() == "*") {
        result = x * y;
    } else if (ui->comboBox->currentText() == "/") {
        if (y == 0) {
            error = true;
        } else {
            result = x / y;
        }
    }

    if (error) {
        ui->label_3->setText("Ошибка!");
    } else {
        ui->label_3->setText( QString::number(result) );
    }
}












#include <QBoxLayout>
#include <QPushButton>

void MainWindow::on_up_clicked()
{
    if (ui->radioButton->isChecked()) {
        ui->radioButton->setChecked(false);

        QPushButton *button = new QPushButton(this);
        button->move(ui->radioButton->x() + 10, ui->radioButton->y() + 22);
        button->resize(16, 16);
        button->show();
    } else {
        ui->radioButton->move(ui->radioButton->x(), ui->radioButton->y() - 16);
    }
}


void MainWindow::on_left_clicked()
{
    if (ui->radioButton->isChecked()) {
        ui->radioButton->setChecked(false);

        QPushButton *button = new QPushButton(this);
        button->move(ui->radioButton->x() + -6, ui->radioButton->y() + 38);
        button->resize(16, 16);
        button->show();
    } else {
        ui->radioButton->move(ui->radioButton->x() - 16, ui->radioButton->y());
    }
}


void MainWindow::on_right_clicked()
{
    if (ui->radioButton->isChecked()) {
        ui->radioButton->setChecked(false);

        QPushButton *button = new QPushButton(this);
        button->move(ui->radioButton->x() + 26, ui->radioButton->y() + 38);
        button->resize(16, 16);
        button->show();
    } else {
        ui->radioButton->move(ui->radioButton->x() + 16, ui->radioButton->y());
    }
}


void MainWindow::on_down_clicked()
{
    if (ui->radioButton->isChecked()) {
        ui->radioButton->setChecked(false);

        QPushButton *button = new QPushButton(this);
        button->move(ui->radioButton->x() + 10, ui->radioButton->y() + 54);
        button->resize(16, 16);
        button->show();
    } else {
        ui->radioButton->move(ui->radioButton->x(), ui->radioButton->y() + 16);
    }
}

void MainWindow::on_right_2_clicked()
{
    ui->radioButton->setChecked(not ui->radioButton->isChecked());
}

