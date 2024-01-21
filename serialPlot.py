import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque
import re
#그래프 활용 가능
ser = serial.Serial("COM7",115200)

fig, ax = plt.subplots()
data1 = deque(maxlen=100)
data2 = deque(maxlen=100)
bar1 = ax.bar(0, 0, width=10,color='gray')
bar2 = ax.bar(30, 0, width=10, color='red')
ax.set_aspect('equal')

def update_graph(frame):
    if ser.in_waiting > 0:
        line = ser.readline().decode("utf-8").rstrip()
        try:
            # data paser (데이터를 읽어서 해석하는 부분)
            number_string = re.findall(r"\d+",line)
            number_int = [int(num) for num in number_string]
            # data store
            data1.append(number_int[0])
            data2.append(number_int[1])
            ax.clear()
            ax.plot(data1, color='red')
            ax.plot(data2, color='blue')
        except ValueError:
            pass

def update_bar(frame):
    if ser.in_waiting>0:
        line = ser.readline().decode("utf-8").rstrip()
        try:
            # data paser
            number_string = re.findall(r"\d+",line)
            number_int = [int(num) for num in number_string]
            # data store 여기에는 그려진 바에서 값을 조정하는것이므로 axcrear 없음
            bar1[0].set_height(number_int[0])
            bar2[0].set_height(number_int[1])
            ax.set_ylim(0,100)
        except ValueError:
            pass

def update_pie(frame):
    if ser.in_waiting>0:
        line = ser.readline().decode("utf-8").rstrip()
        try:
            # data paser
            number_string = re.findall(r"\d+",line)
            number_int = [int(num) for num in number_string]
            #data store
            ax.clear()
            ax.pie([number_int[0],number_int[1]],startangle=90, counterclock=False, colors=['blue','gray'])
             
        except ValueError:
            pass                                                                           
ani = animation.FuncAnimation(fig, update_pie, interval = 1)
plt.show()

ser.close()

#ser = serial.Serial("COM7",115200)
#while True:
#    if ser.in_waiting > 0:
#        data = ser.readline().decode("utf-8").rstrip()
#        print(data)
