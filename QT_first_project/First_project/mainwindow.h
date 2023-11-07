#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>

#include <QSystemTrayIcon>
#include <QCloseEvent>

#include <QSettings>

#include "clock.h"

#define ORGANIZATION_NAME "RandomSoftwareCorp"
#define ORGANIZATION_DOMAIN "www.rsc.ru"
#define APPLICATION_NAME "QSettings Program"

#define SETTINGS_TRAY "settings/tray"
#define IS_WORKING "settings/is_working"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void b_get();

private:
    Ui::MainWindow *ui;
    Clock *clock;
    QTimer *timer;
    QSystemTrayIcon *trayIcon;

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_saveButton_clicked();

    void b_alarm();

    void b_set();

    void b_start();
    void b_stop();
    void b_reset();

    void on_timer();

    void on_btn_click();
    void on_btn_click2();

    void on_pushButton_clicked();

    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_down_clicked();

    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_toggled(bool checked);
    void on_radioButton_toggled(bool checked);
    void on_right_2_clicked();
};
#endif // MAINWINDOW_H
