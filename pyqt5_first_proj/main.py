from PyQt5.QtWidgets import QApplication
from MainWindow import MainWindow
a = QApplication([])

window = MainWindow()
window.show()

a.exec()

