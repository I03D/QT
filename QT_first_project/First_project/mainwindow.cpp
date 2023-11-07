#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTime>
#include <QTimer>
#include <QAction>

#include <QWidget>
#include <QLCDNumber>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

    clock = new Clock(this);
    clock->setGeometry(10, 130, 361, 31);
    clock->show();

    timer = new QTimer(this);

    timer->setInterval(1000);

    clock->set(settings.value(SETTINGS_TRAY, false).toInt());

    if (settings.value(IS_WORKING, false).toBool() == true) {
        clock->start();
    }

    timer->start();

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
    trayIcon->setToolTip("Tray Program" "\n"
                        "Работа со сворачиванием программы в трей");

    QMenu * menu = new QMenu(this);
    QAction * viewWindow = new QAction(tr("Развернуть окно"), this);
    QAction * quitAction = new QAction(tr("Выход"), this);

    connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

    menu->addAction(viewWindow);
    menu->addAction(quitAction);

    trayIcon->setContextMenu(menu);
    trayIcon->show();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));




    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));

    connect(ui->pushButton22, SIGNAL(clicked()), this, SLOT(on_btn_click()));
    connect(ui->pushButton222, SIGNAL(clicked()), this, SLOT(on_btn_click2()));

    connect(ui->Start, SIGNAL(clicked()), this, SLOT(b_start()));
    connect(ui->Stop, SIGNAL(clicked()), this, SLOT(b_stop()));
    connect(ui->Reset, SIGNAL(clicked()), this, SLOT(b_reset()));
    connect(ui->Reset_2, SIGNAL(clicked()), this, SLOT(b_set()));
    connect(ui->Reset_3, SIGNAL(clicked()), this, SLOT(b_alarm()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_saveButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    if(this->isVisible()) {
        event->ignore();
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Tray Program",
                              tr("Приложение свёрнуто в трей. Для того, чтобы "
                                 "развернуть окно приложения, щёлкните по иконке приложения в трее."),
                              icon,
                              2000);
    }
}

void MainWindow::on_saveButton_clicked()
{
    QSettings settings (ORGANIZATION_NAME, APPLICATION_NAME);

    settings.setValue(SETTINGS_TRAY, clock->get());
    settings.setValue(IS_WORKING, clock->isWorking());

    QMessageBox::information(this,
                             tr("Сохранение настроек"),
                             tr("Секунды и состояние работы (вкл/выкл) сохранились!"));
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    if(!this->isVisible()) {
        this->show();
        } else {
            this->hide();
        }
    }
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

