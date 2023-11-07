#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QLCDNumber>
#include <QTimer>
#include <QMessageBox>

class Clock : public QLCDNumber
{
    Q_OBJECT
public:
    Clock(QWidget *parent = nullptr);

    void start();
    void stop();
    void reset();
    void set(int t);
    void set_alarm(int t);

    int get();
    bool isWorking();
private:
    int second;
    int alarm;
    QTimer *timer;

private slots:
    void on_timer();
};

#endif // CLOCK_H
