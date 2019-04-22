import matplotlib.pyplot as plt
import numpy as np
import csv

Y = []
X = []
with open('TimeArray.csv') as f:
	r = csv.reader(f, delimiter=',')
	for row in r:
		for i in range(0, len(row)):
			Y.append(int(row[i]))
			X.append(i)

print(len(Y))
print(len(X))

fig, (ax) = plt.subplots(1, 1)
ax.plot(X, Y, color='black')
ax.fill_between(X, -.1*len(Y), 0, facecolor='red', alpha=0.2)
ax.fill_between(X, 0, max(Y)+.1*len(Y), facecolor='green', alpha=0.2)
ax.set_xlim(0,len(Y)-1)
ax.set_ylim(min(Y)-.1*min(Y), max(Y)+.1*max(Y))
ax.set_title('Score over Time')
ax.set_xlabel('Subsequent Changes to Score')
ax.set_ylabel('Overall Score')
plt.show()