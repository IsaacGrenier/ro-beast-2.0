import sys, serial, time
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel
from PyQt5.QtCore import Qt, QTimer
from main_window_ui import Ui_MainWindow


# Global variables
port = 'COM3'
baud_rate = 9600

paused = False
cancelled = False

curr_height = "XXXXX"
curr_azimuth = "XXXXX"
curr_height_interval = "XXXX"
curr_azimuth_interval = "XXXXX"
curr_height_speed = "XXX"
curr_azimuth_speed = "XXXX"
curr_tilt = "XX"
curr_ecurrent = "XXXX"
curr_rcurrent = "XXXX"

class Beast(QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        # Button initialization
        self.ui.btn_position.clicked.connect(self.btn_position_click)
        self.ui.btn_measure_azimuth.clicked.connect(self.btn_measure_azimuth_click)
        self.ui.btn_measure_height.clicked.connect(self.btn_measure_height_click)
        self.ui.btn_play_pause.clicked.connect(self.btn_play_pause_click)
        self.ui.btn_cancel.clicked.connect(self.btn_cancel_click)

        # Text input initialization (modify as needed)
        self.ui.lnedt_height.setText("104.0")
        self.ui.lnedt_azimuth.setText("0.0")

        self.ui.lnedt_height_range.setText("190.0") # Note: 190 cm input = 193 cm in reality
        self.ui.lnedt_height_interval.setText("10")
        self.ui.lnedt_height_speed.setText("5")
        self.ui.lnedt_azimuth_range.setText("360.0")
        self.ui.lnedt_azimuth_interval.setText("1.0")
        self.ui.lnedt_azimuth_speed.setText("2.0")

        self.ui.lnedt_height.setStyleSheet("color: gray")
        self.ui.lnedt_azimuth.setStyleSheet("color: gray")

        self.ui.lnedt_height_range.setStyleSheet("color: gray")
        self.ui.lnedt_height_interval.setStyleSheet("color: gray")
        self.ui.lnedt_height_speed.setStyleSheet("color: gray")
        self.ui.lnedt_azimuth_range.setStyleSheet("color: gray")
        self.ui.lnedt_azimuth_interval.setStyleSheet("color: gray")
        self.ui.lnedt_azimuth_speed.setStyleSheet("color: gray")

        self.ui.lnedt_height.textChanged.connect(self.lnedt_height_changed)
        self.ui.lnedt_azimuth.textChanged.connect(self.lnedt_azimuth_changed)

        self.ui.lnedt_height_range.textChanged.connect(self.lnedt_height_range_changed)
        self.ui.lnedt_height_interval.textChanged.connect(self.lnedt_height_interval_changed)
        self.ui.lnedt_height_speed.textChanged.connect(self.lnedt_height_speed_changed)
        self.ui.lnedt_azimuth_range.textChanged.connect(self.lnedt_azimuth_range_changed)
        self.ui.lnedt_azimuth_interval.textChanged.connect(self.lnedt_azimuth_interval_changed)
        self.ui.lnedt_azimuth_speed.textChanged.connect(self.lnedt_azimuth_speed_changed)
        
        # Text output initialization
        self.ui.lbl_curr_height_val.setText(curr_height)
        self.ui.lbl_curr_azimuth_val.setText(curr_azimuth)
        self.ui.lbl_curr_height_interval_val.setText(curr_height_interval)
        self.ui.lbl_curr_azimuth_interval_val.setText(curr_azimuth_interval)
        self.ui.lbl_curr_height_speed_val.setText(curr_height_speed)
        self.ui.lbl_curr_azimuth_speed_val.setText(curr_azimuth_speed)
        self.ui.lbl_curr_tilt_val.setText(curr_tilt)
        self.ui.lbl_curr_ecurrent_val.setText(curr_ecurrent)
        self.ui.lbl_curr_rcurrent_val.setText(curr_rcurrent)

        self.ui.lbl_warnings_val.setText("")
        self.ui.lbl_warnings_val.setStyleSheet("color: red")

        #Timer initialization
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.timer_interrupt)
        self.timer.start(2000)

    def timer_interrupt(self): #change to real-time values
        self.ui.lbl_curr_height_val.setText(curr_height)
        self.ui.lbl_curr_azimuth_val.setText(curr_azimuth)
        self.ui.lbl_curr_height_interval_val.setText(curr_height_interval)
        self.ui.lbl_curr_azimuth_interval_val.setText(curr_azimuth_interval)
        self.ui.lbl_curr_height_speed_val.setText(curr_height_speed)
        self.ui.lbl_curr_azimuth_speed_val.setText(curr_azimuth_speed)
        self.ui.lbl_curr_tilt_val.setText(curr_tilt)
        self.ui.lbl_curr_ecurrent_val.setText(curr_ecurrent)
        self.ui.lbl_curr_rcurrent_val.setText(curr_rcurrent)

    def lnedt_height_changed(self):
        self.ui.lnedt_height.setStyleSheet("color: black")

    def lnedt_azimuth_changed(self):
        self.ui.lnedt_azimuth.setStyleSheet("color: black")

    def lnedt_height_range_changed(self):
        self.ui.lnedt_height_range.setStyleSheet("color: black")

    def lnedt_height_interval_changed(self):
        self.ui.lnedt_height_interval.setStyleSheet("color: black")

    def lnedt_height_speed_changed(self):
        self.ui.lnedt_height_speed.setStyleSheet("color: black")

    def lnedt_azimuth_range_changed(self):
        self.ui.lnedt_azimuth_range.setStyleSheet("color: black")

    def lnedt_azimuth_interval_changed(self):
        self.ui.lnedt_azimuth_interval.setStyleSheet("color: black")

    def lnedt_azimuth_speed_changed(self):
        self.ui.lnedt_azimuth_speed.setStyleSheet("color: black")

    def btn_position_click(self):
        global paused 
        global cancelled
        paused = False
        cancelled = False
        self.ui.lbl_warnings_val.setText("")
        desired_height = self.ui.lnedt_height.text()
        desired_azimuth = self.ui.lnedt_azimuth.text()
        if (float(desired_height) >= 104 and float(desired_height) <= 190) and (float(desired_azimuth) >= 0 and float(desired_azimuth) <= 360):
            self.ui.lbl_warnings_val.setText("")
            # while loops untested
            while len(desired_height) < 5:
                desired_height = desired_height + "0"
            while len(desired_azimuth) < 5:
                desired_azimuth = desired_azimuth + "0"
            transmit_UART('a')
            for i in 5:
                time.sleep(0.5)
                transmit_UART(desired_height[i])
            for i in 5:
                time.sleep(0.5)
                transmit_UART(desired_azimuth[i])
        else:
            if float(desired_height) < 104 or float(desired_height) > 190:
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired height is out of range (104 cm - 190 cm, float)") # Note: 190 cm input = 193 cm in reality
            if float(desired_azimuth) < 0 or float(desired_azimuth) > 360:
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired azimuth is out of range (0\u00b0 - 360\u00b0, float)")
    

    def btn_measure_azimuth_click(self):
        global paused 
        global cancelled
        paused = False
        cancelled = False
        self.ui.lbl_warnings_val.setText("")
        desired_azimuth_range = self.ui.lnedt_azimuth_range.text()
        desired_azimuth_interval = self.ui.lnedt_azimuth_interval.text()
        desired_azimuth_speed = self.ui.lnedt_azimuth_speed.text()
        if (float(desired_azimuth_range) >= 0.1 and float(desired_azimuth_range) <= 360) and \
            (float(desired_azimuth_interval) >= 0.1 and float(desired_azimuth_interval) <= 99.9) and \
                (float(desired_azimuth_speed) >= 2 and float(desired_azimuth_speed) <= 30):
            self.ui.lbl_warnings_val.setText("")
            # while loops untested
            while len(desired_azimuth_range) < 5:
                desired_azimuth_range = "0" + desired_azimuth_range
            while len(desired_azimuth_interval) < 4:
                desired_azimuth_interval = "0" + desired_azimuth_interval
            while len(desired_azimuth_speed) < 4:
                desired_azimuth_speed = "0" + desired_azimuth_speed
            transmit_UART('b')
            for i in 5:
                time.sleep(0.5)
                transmit_UART(desired_azimuth_range[i])
            for i in 4:
                time.sleep(0.5)
                transmit_UART(desired_azimuth_interval[i])
            for i in 4:
                time.sleep(0.5)
                transmit_UART(desired_azimuth_speed[i])
        else:
            if float(desired_azimuth_range) < 0.1 or float(desired_azimuth_range) > 360:
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired azimuth range is out of range (0.1\u00b0 - 360\u00b0, float)")
            if float(desired_azimuth_interval) < 0.1 or float(desired_azimuth_interval) > 99.9:
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired azimuth measurement interval is out of range (0\u00b0 - 99.9\u00b0, float)")
            if float(desired_azimuth_speed) < 2 or float(desired_azimuth_speed) > 30:
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired rotation speed is out of range (2\u00b0/s - 30\u00b0/s, float)")
            
    def btn_measure_height_click(self):
        global paused 
        global cancelled
        paused = False
        cancelled = False
        self.ui.lbl_warnings_val.setText("")
        desired_height_range = self.ui.lnedt_height_range.text()
        desired_height_interval = self.ui.lnedt_height_interval.text()
        desired_height_speed = self.ui.lnedt_height_speed.text()
        if (float(desired_height_range) >= 0.1 and float(desired_height_range) <= (190 - float(curr_height))) and \
            (float(desired_height_interval) >= 1 and float(desired_height_interval) <= 10*float(desired_height_range)) and \
                (float(desired_height_speed) >= 0.1 and float(desired_height_speed) <= 10):
            self.ui.lbl_warnings_val.setText("")
            # while loops untested
            while len(desired_height_range) < 5:
                desired_height_range = "0" + desired_height_range
            while len(desired_height_interval) < 3:
                desired_height_interval = "0" + desired_height_interval
            while len(desired_height_speed) < 4:
                desired_height_speed = "0" +desired_height_speed
            transmit_UART('c')
            for i in 5:
                time.sleep(0.5)
                transmit_UART(desired_height_range[i])
            for i in 3:
                time.sleep(0.5)
                transmit_UART(desired_height_interval[i])
            for i in 4:
                time.sleep(0.5)
                transmit_UART(desired_height_speed[i])
        else:
            if float(desired_height_range) < 0.1 or float(desired_height_range) > (190 - float(curr_height)):
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired height range is out of range (0.1 cm - (190 - current height) cm, float)")
            if float(desired_height_interval) < 1 or float(desired_height_interval) > 10*float(desired_height_range):
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired height measurement interval is out of range (1 mm - (height range) mm, float)")
            if float(desired_height_speed) < 0.1 or float(desired_height_speed) > 10:
                self.ui.lbl_warnings_val.setText(self.ui.lbl_warnings_val.text() + "\nError: desired elevation speed is out of range (0.1 mm/s - 10.0 mm/s, float)")

    # unconfigured on dsPIC side
    def btn_play_pause_click(self):
        global paused 
        paused = paused^True
        transmit_UART('d')


    def btn_cancel_click(self):
        global cancelled 
        cancelled = True
        transmit_UART('e')


def transmit_UART(char_tx):
    global port, baud_rate
    ser = serial.Serial(port, baud_rate, timeout=1)
    ser.write(char_tx.encode())
    ser.close()

def receive_UART():
    global port, baud_rate
    ser = serial.Serial(port, baud_rate, timeout=1)
    char_rx = ser.read(1).decode()
    ser.close()
    return char_rx

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = Beast()
    window.show()
    sys.exit(app.exec_())

# not functioning
while True:
    message_id = receive_UART()
    # A: current height
    # B: current azimuth
    # C: current height interval
    # D: current azimuth interval
    # E: current height speed
    # F: current azimuth speed
    # G: current tilt
    # H: current elevation current
    # I: current rotation current
    if message_id == 'A':
       for i in 5:
           curr_height[i] = receive_UART()
    if message_id == 'B':
        for i in 5:
            curr_azimuth[i] = receive_UART()
    if message_id == 'C':
        for i in 4:
            curr_height_interval[i] = receive_UART()
    if message_id == 'D':
        for i in 5:
            curr_azimuth_interval[i] = receive_UART()
    if message_id == 'E':
        for i in 3:
            curr_height_speed[i] = receive_UART()
    if message_id == 'F':
        for i in 4:
            curr_azimuth_speed[i] = receive_UART()
    if message_id == 'G':
        for i in 2:
            curr_tilt[i] = receive_UART()
    if message_id == 'H':
        for i in 4:
            curr_ecurrent[i] = receive_UART()
    if message_id == 'I':
        for i in 4:
            curr_rcurrent[i] = receive_UART()