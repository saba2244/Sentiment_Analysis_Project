import matplotlib.pyplot as plt
import numpy as np
import csv

#Python script uses matplotlib to create a graph of the moving overall score as text is interpreted.
#The script is called from within the c++ driver program. 

# Stores the values from the CSV into an array
Y = []
X = []
with open('TimeArray.csv') as f:
	r = csv.reader(f, delimiter=',')
	for row in r:
		for i in range(0, len(row)-1):
			Y.append(int(row[i]))
			X.append(i)

# Creates the plot for the score over time.
fig, (ax) = plt.subplots(1, 1)
ax.plot(X, Y, color='black')
ax.fill_between(X, min(Y), 0, facecolor='red', alpha=0.2)
ax.fill_between(X, 0, max(Y), facecolor='green', alpha=0.2)
ax.set_xlim(0,len(Y)-1)
ax.set_ylim(min(Y), max(Y))
ax.set_title('Score over Time')
ax.set_xlabel('Subsequent Changes to Score')
ax.set_ylabel('Overall Score')
plt.show()
