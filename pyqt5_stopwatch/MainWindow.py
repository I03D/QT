from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton, QMessageBox
from PyQt5.QtCore import QTimer
from stopwatch import Clock

class MainWindow(QMainWindow):

    def __init__(self):
        super().__init__()

        self.clock = Clock()
        self.clock.setGeometry(300, 300, 500, 300);
        self.clock.show()
        self.clock.set_alarm(5)

        self.setGeometry(100, 300, 200, 300)

        b1 = QPushButton('Старт', self)
        b1.setGeometry(0, 0, 200, 50)
        b1.show()
        b1.clicked.connect(self.cb1)

        # button.clicked.connect(self.on_click)

#        clock = Clock()
#        clock.setGeometry(300, 40, 500, 300);
#        clock.show()
#        clock.set_alarm(5)
#        clock.start()

    def cb1(self):
        self.clock.start()
#        timer = QTimer();
#
#        timer.setInterval(1000);
#
#        timer.start()
#
#        timer.timeout.connect(self.on_timer());
#
#    def on_timer(self):
#        timer.clock.second += 1
#        timer.clock.display(self.second)
#
#        msg=QMessageBox(self)
#        msg.setText('Чего нажал?!')
#        msg.exec()

