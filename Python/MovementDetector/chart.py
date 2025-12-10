import matplotlib.pyplot as plt
import numpy as np
names = []
marks = []

f = open('output.txt','r')
for row in f:
    row = row.split(' ')
    names.append(row[0])
    marks.append(int(row[1]))

plt.bar(names, marks, color = 'g', label = 'File Data')

plt.xlabel('Time', fontsize = 12)
plt.ylabel('Dots', fontsize = 12)

plt.title('Dots Over Time', fontsize = 20)
plt.legend()
plt.show()
