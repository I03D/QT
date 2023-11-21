# from PyQt5.QtWidgets import QWidget, QLCDNumber, QTimer
# from PyQt5 import QtWidgets, QLCDNumber
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import QTimer
from PyQt5.QtWidgets import QLCDNumber, QMessageBox

# aa = QApplication([])

class Clock(QLCDNumber):
    timer = QTimer()
    def __init__(self):
        super().__init__()
        self.second = 0
        self.alarm = -1
        self.timer.setInterval(1000)

        # connect(timer, SIGNAL(timeout()), this, SLOT(on_timer()));
        self.timer.timeout.connect(self.on_timer)

    def on_timer(self):
        self.second += 1
        self.display(self.second) # Если делать "second += 1" в display, то при срабатывании будильника, последнее время может не отобразиться

        if self.second == self.alarm:
            self.stop()
            self.alarm = -1

            msg = QMessageBox()
            msg.setText("Время вышло!!!")
            msg.exec()

    def isWorking():
        return self.timer.isActive()

    def get():
        return(second)

    def start(self):
        if not self.timer.isActive():
            self.timer.start()

    def stop():
        if self.timer.isActive():
            self.timer.stop()

    def reset():
        second = 0
        display(0)

    def set(self, t):
        second = t
        display(t)

    def set_alarm(self, t):
        alarm = t

        msg = QMessageBox()
        msg.setText("Будильник сработает в " + str(t) + " секунд.")
        msg.exec()

