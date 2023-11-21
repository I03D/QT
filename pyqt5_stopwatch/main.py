from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QPushButton
from MainWindow import MainWindow

a = QApplication([])

window = MainWindow()
window.show()

a.exec()

