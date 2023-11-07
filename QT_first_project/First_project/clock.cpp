#include "clock.h"

Clock::Clock(QWidget *parent) : QLCDNumber(parent)
{
    second = 0;
    alarm = -1;
    timer = new QTimer(this);
    timer->setInterval(1000);

    connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
}

void Clock::on_timer()
{
    second++;
    display(second); // Если делать second++ в display, то при срабатывании будильника, последнее время может не отобразиться

    if (second == alarm) {
        this->stop();
        alarm = -1;

        QMessageBox msg;
        msg.setText("Время вышло!!!");
        msg.exec();
    }
}

bool Clock::isWorking() {
    return timer->isActive();
}

int Clock::get() {
    return(second);
}

void Clock::start() {
    if (not timer->isActive()) timer->start();
}

void Clock::stop() {
    if (timer->isActive()) timer->stop();
}

void Clock::reset() {
    second = 0;
    display(0);
}

void Clock::set(int t) {
    second = t;
    display(t);
}

void Clock::set_alarm(int t) {
    alarm = t;

    QMessageBox msg;
    msg.setText("Будильник сработает в " + QString::number(t) + " секунд.");
    msg.exec();

}
